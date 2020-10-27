/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:37:31 by qperrot-          #+#    #+#             */
/*   Updated: 2020/10/12 17:00:55 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <memory>
#include <limits>
#include "list.hpp"

namespace ft {

	template<typename T, typename Container = ft::list<T> >
	class stack
	{
		public:
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;
			typedef typename Container::size_type size_type;

		protected:
			Container _c;

		public:
			explicit stack( const Container& cont = Container() );
			stack( const stack& other );
			stack& operator=( const stack& other );
			virtual ~stack();
			reference top();
			const_reference top() const;
			bool empty() const;
			size_type size() const;
			void pop();
			void push (const value_type& val);
			friend bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {

				return (lhs._c == rhs._c);
			}

			friend bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {

				return (lhs._c != rhs._c);
			}

			friend bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {

				return (lhs._c < rhs._c);
			}

			friend bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {

				return (lhs._c <= rhs._c);
			}

			friend bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {

				return (lhs._c > rhs._c);
			}

			friend bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {

				return (lhs._c >= rhs._c);
			}		
	};

	template< typename T, typename Container >
	stack<T, Container>::stack( const Container& cont) : _c(cont) { }

	template< typename T, typename Container >
	stack<T, Container>::stack( const stack& other ) : _c(other._c) { }

	template< typename T, typename Container >
	stack<T, Container>::~stack() { }

	template< typename T, typename Container >
	stack<T, Container> & stack<T, Container>::operator=( const stack& other ) { _c = other._c ; return *this;}

	template< typename T, typename Container >
	typename stack<T, Container>::reference	stack<T, Container>::top() { return _c.back(); }

	template< typename T, typename Container >
	typename stack<T, Container>::const_reference	stack<T, Container>::top() const { return _c.back(); }

	template< typename T, typename Container >
	bool stack<T, Container>::empty() const { return _c.empty(); }

	template< typename T, typename Container >
	typename stack<T, Container>::size_type	stack<T, Container>::size() const { return _c.size(); }

	template< typename T, typename Container >
	void stack<T, Container>::pop() { return _c.pop_back(); }

	template< typename T, typename Container >
	void	stack<T, Container>::push (const value_type& val) { return _c.push_back(val); }
	
}
#endif