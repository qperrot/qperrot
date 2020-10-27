/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:03:48 by qperrot-          #+#    #+#             */
/*   Updated: 2020/10/12 17:20:02 by qperrot-         ###   ########.fr       */
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
	class queue
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
			explicit queue( const Container& cont = Container() );
			queue( const queue& other );
			queue& operator=( const queue& other );
			virtual ~queue();
			reference back();
			const_reference back() const;
			bool empty() const;
			reference front();
			const_reference front() const;
			size_type size() const;
			void pop();
			void push (const value_type& val);
			friend bool operator==( const queue<T,Container>& lhs, const queue<T,Container>& rhs ) {

				return (lhs._c == rhs._c);
			}

			friend bool operator!=( const queue<T,Container>& lhs, const queue<T,Container>& rhs ) {

				return (lhs._c != rhs._c);
			}

			friend bool operator<( const queue<T,Container>& lhs, const queue<T,Container>& rhs ) {

				return (lhs._c < rhs._c);
			}

			friend bool operator<=( const queue<T,Container>& lhs, const queue<T,Container>& rhs ) {

				return (lhs._c <= rhs._c);
			}

			friend bool operator>( const queue<T,Container>& lhs, const queue<T,Container>& rhs ) {

				return (lhs._c > rhs._c);
			}

			friend bool operator>=( const queue<T,Container>& lhs, const queue<T,Container>& rhs ) {

				return (lhs._c >= rhs._c);
			}		
	};

	template< typename T, typename Container >
	queue<T, Container>::queue( const Container& cont) : _c(cont) { }

	template< typename T, typename Container >
	queue<T, Container>::queue( const queue& other ) : _c(other._c) { }

	template< typename T, typename Container >
	queue<T, Container>::~queue() { }

	template< typename T, typename Container >
	queue<T, Container> & queue<T, Container>::operator=( const queue& other ) { _c = other._c ; return *this;}

	template< typename T, typename Container >
	typename	queue<T, Container>::reference queue<T, Container>::back() { return _c.back(); }

	template< typename T, typename Container >
	typename	queue<T, Container>::const_reference queue<T, Container>::back() const { return _c.back(); }

	template< typename T, typename Container >
	typename	queue<T, Container>::reference queue<T, Container>::front() { return _c.front(); }

	template< typename T, typename Container >
	typename	queue<T, Container>::const_reference queue<T, Container>::front() const { return _c.front(); }

	template< typename T, typename Container >
	bool queue<T, Container>::empty() const { return _c.empty(); }

	template< typename T, typename Container >
	typename queue<T, Container>::size_type	queue<T, Container>::size() const { return _c.size(); }

	template< typename T, typename Container >
	void queue<T, Container>::pop() { return _c.pop_front(); }

	template< typename T, typename Container >
	void	queue<T, Container>::push (const value_type& val) { return _c.push_back(val); }
	
}
#endif