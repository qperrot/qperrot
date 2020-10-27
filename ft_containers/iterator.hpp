/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 09:42:56 by qperrot-          #+#    #+#             */
/*   Updated: 2020/10/21 15:59:49 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <memory>
#include <limits>

namespace ft {
	template< bool B, class T = void >
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template< class T >
	struct is_integral { static const bool value = false; };

	template< >
	struct is_integral< bool > { static const bool value = true; };

	template< >
	struct is_integral< char > { static const bool value = true; };

	template< >
	struct is_integral< signed char > { static const bool value = true; };

	template< >
	struct is_integral< unsigned char > { static const bool value = true; };

	template< >
	struct is_integral< wchar_t > { static const bool value = true; };

	template< >
	struct is_integral< short > { static const bool value = true; };

	template< >
	struct is_integral< unsigned short > { static const bool value = true; };

	template< >
	struct is_integral< int > { static const bool value = true; };

	template< >
	struct is_integral< unsigned int > { static const bool value = true; };

	template< >
	struct is_integral< long > { static const bool value = true; };

	template< >
	struct is_integral< unsigned long > { static const bool value = true; };
}

namespace ft {
	template<typename T>
	struct Node
	{
			T			_value;
			Node<T>*	_next;
			Node<T>*	_prev;
			Node(const T &val, Node<T>* next, Node<T>* prev);
	};
}

namespace ft {
	template <typename Iter> 
	class ReverseIterator {
		public:
			typedef ReverseIterator<Iter> reverse_iterator;
			typedef Iter iterator_type;
			typedef typename Iter::difference_type difference_type;
			typedef typename Iter::value_type value_type;
			typedef typename Iter::pointer pointer;
			typedef typename Iter::reference reference;
			typedef std::bidirectional_iterator_tag iterator_category;

		protected:
			Iter	_current;

		public:
			ReverseIterator() : _current(nullptr) {}
			explicit ReverseIterator( iterator_type x ) : _current(x) {}
			template< class U >
			ReverseIterator( const ReverseIterator<U>& other ) : _current(other.base()) {}
			virtual ~ReverseIterator() {};
			template< class U >
			reverse_iterator& operator=( const ReverseIterator<U>& other ) { this->_current = other.base(); return *this;}
			iterator_type base() const { return _current; }
			
			bool operator!=(const reverse_iterator& itr) const { return this->_current != itr._current; }
			/* Overload for the dereference operator * */
			reference operator*() const { Iter it(_current); --it; return *it; }
			
			pointer operator->() const { return (&(operator*())); }
			/* Overload for the postincrement operator ++ */
			reverse_iterator operator++(int) { reverse_iterator temp = *this; --_current; return temp; }

			reverse_iterator operator--(int) { reverse_iterator temp = *this; ++_current; return temp; }

			reverse_iterator &operator++() { --_current; return *this; }

			reverse_iterator &operator--() { ++_current; return *this; }

			reverse_iterator operator+( difference_type n ) const {reverse_iterator(base() - n);}

			reverse_iterator operator-( difference_type n ) const {reverse_iterator(base() + n);}

			reverse_iterator& operator+=( difference_type n ) {reverse_iterator(_current -= n);}

			reverse_iterator& operator-=( difference_type n ) {reverse_iterator(_current += n);}

			reverse_iterator operator[]( difference_type n ) const { return (base()[-n-1]); }
		}; /* End of class reverse_iterator */
}



#endif