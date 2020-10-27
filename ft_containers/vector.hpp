/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:38:56 by qperrot-          #+#    #+#             */
/*   Updated: 2020/10/26 15:05:53 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <limits>
#include "iterator.hpp"

namespace ft {

	template<typename T, typename A = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;
			typedef A allocator_type;
			typedef typename A::reference reference;
			typedef typename A::const_reference const_reference;
			typedef typename A::pointer pointer;
			typedef typename A::const_pointer const_pointer;
			typedef typename A::difference_type difference_type;
			typedef typename A::size_type size_type;

		private:
			allocator_type	_alloc;
			size_type				_size;
			size_type				_capacity;
			T*				_array;
			template <class InputIterator>
			size_type distance(InputIterator first, InputIterator last,  typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type Iter = InputIterator());

		public:
			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(), typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type Iter = InputIterator());
			vector (const vector& x);
			virtual ~vector();
			class iterator;
			class const_iterator;
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type Iter = InputIterator());
			void assign (size_type n, const value_type& val);
			reference at (size_type n);
			const_reference at (size_type n) const;
			reference back();
			const_reference back() const;
			size_type capacity() const;
			void clear();
			bool empty() const;
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			reference front();
			const_reference front() const;
			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type Iter = InputIterator());
			size_type max_size() const;
			vector& operator= (const vector& x);
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
			void pop_back();
			void push_back (const value_type& val);
			void reserve (size_type n);
			void resize (size_type n, value_type val = value_type());
			size_type size() const;
			void swap (vector& x);

			class iterator {
				public:
					typedef typename A::difference_type difference_type;
        			typedef typename A::value_type value_type;
					typedef typename A::reference reference;
					typedef typename A::pointer pointer;
					typedef std::random_access_iterator_tag iterator_category;

				private:
					T*	_index;

				public:
					iterator(T*	i) : _index(i) {}
					iterator() : _index(nullptr) {}
					iterator &operator=( const iterator& other) { this->_index = other.geti(); return *this; }
					virtual ~iterator() {};
					
					T * geti() const {
						return this->_index;
					}
					/* Overload for the comparison operator == */
					bool operator==(const iterator& itr) const { return this->_index == itr._index; } 
					/* Overload for the comparison operator != */
					bool operator!=(const iterator& itr) const { return this->_index != itr._index; }
					bool operator<(const iterator& itr) const { return this->_index < itr._index; }
					bool operator>(const iterator& itr) const { return this->_index > itr._index; }
					bool operator<=(const iterator& itr) const {
						if (this->_index != itr._index)
							return this->_index < itr._index;
						return true;
					}
					bool operator>=(const iterator& itr) const {
						if (this->_index != itr._index)
							return this->_index > itr._index;
						return true;
					}
					/* Overload for the dereference operator * */
					reference operator*() const { return  *this->_index; }

					pointer operator->() const { return this->_index; }
					/* Overload for the postincrement operator ++ */
					iterator operator++(int) { return iterator(this->_index++); }

					iterator &operator++() { this->_index++; return *this; }

					iterator operator--(int) { return iterator(this->_index--); }

					iterator &operator--() { --this->_index; return *this; }

					iterator operator+( difference_type n ) const {return iterator(this->_index + n);}

					iterator operator-( difference_type n ) const {return iterator(this->_index - n);}

					iterator& operator+=( difference_type n ) {this->_index += n; return *this;}

					iterator& operator-=( difference_type n ) {this->_index -= n; return *this;}

					iterator operator[]( difference_type n ) const { return (_index[n]); }
			}; /* End of inner class iterator */
			class const_iterator {
				public:
					typedef const T& reference;
					typedef const T* pointer;
					typedef typename A::difference_type difference_type;
        			typedef typename A::value_type value_type;
					typedef std::random_access_iterator_tag iterator_category;

				private:
					T*	_index;

				public:
					const_iterator(T*	i) : _index(i) {}
					const_iterator() : _index(nullptr) {}
					const_iterator &operator=( const const_iterator& other) { this->_index = other.geti(); return *this; }
					const_iterator(const iterator &other) : _index(other.geti()) { }
					virtual ~const_iterator() {};
					
					T * geti() const {
						return this->_index;
					}
					/* Overload for the comparison operator == */
					bool operator==(const const_iterator& itr) const { return this->_index == itr._index; } 
					/* Overload for the comparison operator != */
					bool operator!=(const const_iterator& itr) const { return this->_index != itr._index; } 
					/* Overload for the dereference operator * */
					reference operator*() const { return  *this->_index; }

					pointer operator->() const { return this->_index; }
					/* Overload for the postincrement operator ++ */
					const_iterator operator++(int) { return const_iterator(this->_index++); }

					const_iterator &operator++() { ++this->_index; return *this; }

					const_iterator operator--(int) { return const_iterator(this->_index--); }

					const_iterator &operator--() { --this->_index; return *this; }

					const_iterator operator+( difference_type n ) const {return const_iterator(this->_index + n);}

					const_iterator operator-( difference_type n ) const {return const_iterator(this->_index - n);}

					const_iterator& operator+=( difference_type n ) {this->_index += n; return *this;}

					const_iterator& operator-=( difference_type n ) {this->_index -= n; return *this;}

					const_iterator operator[]( difference_type n ) const { return (_index[n]); }
			}; /* End of inner class iterator */

			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;

    		iterator begin() { return iterator(this->_array); }
			
			const_iterator begin() const { return const_iterator(this->_array); }
			
			iterator end() { return iterator(this->_array + this->_size); }
			
			const_iterator end() const { return const_iterator(this->_array + this->_size); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }

			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

			reverse_iterator rend() { return reverse_iterator(begin()); }

			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
	};

	template <class T, class A>
	bool operator== (const vector<T,A>& lhs, const vector<T,A>& rhs) {

		if (lhs.size() != rhs.size())
		return false;
		typename vector<T, A>::const_iterator it = lhs.begin();
		typename vector<T, A>::const_iterator it2 = rhs.begin();
		for ( ; it != lhs.end() && it2 != rhs.end() ; ++it, ++it2)
		{
			if (*it != *it2)
				return false;
		}
		return true;
	}

	template <class T, class A>
	bool operator!= (const vector<T,A>& lhs, const vector<T,A>& rhs) {

		if (!(lhs == rhs))
			return true;
		return false;
	}

	template <class T, class A>
	bool operator<  (const vector<T,A>& lhs, const vector<T,A>& rhs) {

		typename vector<T, A>::const_iterator it = lhs.begin();
		typename vector<T, A>::const_iterator it2 = rhs.begin();
		for ( ; it != lhs.end() && it2 != rhs.end() ; ++it, ++it2)
		{
			if ((*it != *it2))
				return (*it < *it2);
		}
		if (lhs.size() == rhs.size())
			return false;
		return lhs.size() < rhs.size();
	}

	template <class T, class A>
	bool operator<= (const vector<T,A>& lhs, const vector<T,A>& rhs) {
		
		if (!(lhs == rhs))
			return lhs < rhs;
		return true;
	}

	template <class T, class A>
	bool operator>  (const vector<T,A>& lhs, const vector<T,A>& rhs) {

		typename vector<T, A>::const_iterator it = lhs.begin();
		typename vector<T, A>::const_iterator it2 = rhs.begin();
		for ( ; it != lhs.end() && it2 != rhs.end() ; ++it, ++it2)
		{
			if ((*it != *it2))
				return (*it > *it2);
		}
		if (lhs.size() == rhs.size())
			return false;
		return lhs.size() > rhs.size();
	}

	template <class T, class A>
	bool operator>= (const vector<T,A>& lhs, const vector<T,A>& rhs) {
	
		if (!(lhs == rhs))
			return lhs > rhs;
		return true;
	}

	template<typename T, typename A >
	template <class InputIterator>
	typename vector<T,A>::size_type vector<T,A>::distance (InputIterator first, InputIterator last,  typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type) {

		size_type result = 0;
    	while (first != last) {
       		++first;
        	++result;
    	}
    	return result;
	}

//	template <class T>
  //	void swap (T &x, T &y) {
		
//		T tmp(x);

//		x = y;
//		y = tmp;
//	}

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }

	template<typename T, typename A >
	vector<T,A>::vector (const allocator_type& alloc) : _alloc(alloc), _size(0), _capacity(0), _array(nullptr) {}

	template<typename T, typename A >
	vector<T,A>::vector (size_type n, const value_type& val, const allocator_type& alloc) : _alloc(alloc), _size(n), _capacity(n) {

		_array = _alloc.allocate(n);
		_alloc.construct(_array, 0);
		for (size_type i = 0; i < n; i++)
			_array[i] = val;
	}

	template<typename T, typename A >
	template <class InputIterator>
	vector<T,A>::vector (InputIterator first, InputIterator last,
		const allocator_type& alloc , typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type) :  _alloc(alloc) {

		size_type n = distance(first, last);
		_array = _alloc.allocate(n);
		_alloc.construct(_array, 0);
		for (size_type i = 0; i < n; i++) {
			_array[i] = *first;
			first++;
		}
		_capacity = n;
		_size = n;
	}

	template<typename T, typename A >
	vector<T,A>::vector (const vector& x) {

		size_type n = distance(x.begin(), x.end());
		_array = _alloc.allocate(n);
		_alloc.construct(_array, 0);
		for (size_type i = 0; i < n; i++) {
			_array[i] = x._array[i];
		}
		_capacity = x.capacity();
		_size = x.size();
	}

	template<typename T, typename A >
	vector<T,A>::~vector() { 
		if (_capacity) {
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.destroy(_array + i);
			}
		}
		_alloc.deallocate(_array, _capacity);
	}

	template<typename T, typename A >
	vector<T,A> & vector<T,A>::operator= (const vector& x) {

		assign(x.begin(), x.end());
		return (*this);
	}

	template<typename T, typename A >
	typename vector<T,A>::reference vector<T,A>::operator[] (size_type n) { return _array[n]; }

	template<typename T, typename A >
	typename vector<T,A>::const_reference vector<T,A>::operator[] (size_type n) const { return _array[n]; }


	template<typename T, typename A >
	template <class InputIterator>
	void vector<T,A>::assign (InputIterator first, InputIterator last,  typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type) {

		clear();
		size_type result = distance(first, last);
		if (result > this->capacity())
		{
			_alloc.deallocate(_array, _capacity);
			_array = _alloc.allocate(result);
			_alloc.construct(_array, 0);
			_size = result;
			_capacity = result;
		}

		for (size_type i = 0; i < result; i++) {
			_array[i] = *first;
			++first;
		}
		_size = result;
	}

	template<typename T, typename A >
	void vector<T,A>::assign (size_type n, const value_type& val) {

		clear();
		if (n > capacity()) {
			try
			{
				this->reserve(n);
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << '\n';
				return ;
			}
		}
		for (size_type i = 0; i < n; i++)
			_array[i] = val;
		_size = n;
	}

	template<typename T, typename A >
	typename vector<T,A>::reference	vector<T,A>::at (size_type n) {

		if (n >= size())
			throw std::out_of_range("index is out of range");
		return (_array[n]);
	}

	template<typename T, typename A >
	typename vector<T,A>::const_reference	vector<T,A>::at (size_type n) const {
		if (n >= size())
			throw std::out_of_range("index is out of range");
		return (_array[n]);
	}

	template<typename T, typename A >
	typename vector<T,A>::reference vector<T,A>::back() { return (*(--(end()))); }

	template<typename T, typename A >
	typename vector<T,A>::const_reference vector<T,A>::back() const { return (*(--(end()))); }

	template<typename T, typename A >
	void	vector<T,A>::clear() {

		erase(begin(), end());
	}

	template<typename T, typename A >
	typename vector<T,A>::size_type	vector<T,A>::capacity() const { return this->_capacity; }

	template<typename T, typename A >
	bool vector<T,A>::empty() const {
		if (size() == 0)
			return true;
		return false;
	}

	template<typename T, typename A >
	typename vector<T,A>::iterator	vector<T,A>::erase (iterator position) {

		iterator lst = position;
		lst++;
		return (erase(position, lst));
	}

	template<typename T, typename A >
	typename vector<T,A>::iterator	vector<T,A>::erase (iterator first, iterator last) {

		if (first == last)
			return last;
		size_type new_size = distance(first, last);
		for (iterator it = first; it != last; it++)
		{
			_alloc.destroy(it.geti());
		}
		iterator lst = last;
		if (last != end())
		{
			for (iterator it = first;  lst != end(); it++, lst++)
			{
				_alloc.construct(it.geti(), *lst);
				this->_alloc.destroy(lst.geti());
			}
		}
		_size = _size - new_size;
		return (first);
	}

	template<typename T, typename A >
	typename vector<T,A>::reference vector<T,A>::front() { return (*begin()); }

	template<typename T, typename A >
	typename vector<T,A>::const_reference vector<T,A>::front() const { return (*begin()); }

	template<typename T, typename A >
	typename vector<T,A>::iterator vector<T,A>::insert (iterator position, const value_type& val) {

		size_type dist = distance(begin(), position);
		if ((size() + 1) > capacity())
		{
			try
			{
				reserve(capacity() * 2);
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << '\n';
				return (begin());
			}
		}
		size_type new_size = _size + 1;
		for (size_type i = size() + 1; i > dist + 1; i--)
		{
			_alloc.construct(_array + i - 1 , _array[i - 2]);
			_alloc.destroy(_array + i - 2);
		}
		_alloc.construct(_array + dist, val);
		_size = new_size;
		return (_array + dist);
	}

	template<typename T, typename A >
	void vector<T,A>::insert (iterator position, size_type n, const value_type& val) {

		size_type dist = distance(begin(), position);
		if ((size() + n) > capacity())
		{
			try
			{
				if ((size() + n) > (capacity() * 2))
					reserve((size() + n));
				else
					reserve(capacity() * 2);
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << '\n';
				return ;
			}
		}
		while (n > 0)
		{
			insert(_array + dist, val);
			dist++;
			--n;
		}
		return ;
	}

	template<typename T, typename A >
	template <class InputIterator>
	void vector<T,A>::insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type) {

		size_type dist = distance(begin(), position);
		size_type n = distance(first, last);
		if ((size() + n) > capacity())
		{
			try
			{
				reserve((size() + n));
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << '\n';
				return ;
			}
		}
		while (n > 0)
		{
			insert(_array + dist, *(first + (n - 1)));
			n--;
		}
	}

	template<typename T, typename A>
	typename vector<T, A>::size_type	vector<T, A>::max_size() const {

		return (static_cast<size_type>(std::numeric_limits<ft::vector<T, A>::size_type>::max())/ sizeof(T));
	}

	template<typename T, typename A>
	void	vector<T, A>::pop_back() {

		erase(--end());
	}

	template<typename T, typename A>
	void	vector<T, A>::push_back (const value_type& val) {

		insert(end(), val);
	}

	template<typename T, typename A >
	void vector<T,A>::reserve(size_type n) {

		if (n > max_size())
			throw std::length_error("Max size reached");
		if (n > capacity())
		{
			T*	new_pointer = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(&new_pointer[i], _array[i]);
				_alloc.destroy(&_array[i]);
			}
			_alloc.deallocate(_array, _capacity);
			_array = new_pointer;
			_capacity = n;
		}
		return ;
	}

	template<typename T, typename A >
	void	vector<T,A>::resize (size_type n, value_type val) {

		if (n < size())
			erase(_array + n, _array + size());
		else
			insert(end(), n - size(), val);
		
	}

	template<typename T, typename A >
	typename vector<T,A>::size_type vector<T,A>::size() const { return _size; }

	template<typename T, typename A>
	void 	vector<T,A>::swap (vector& x) {

		ft::swap(_alloc, x._alloc);
		ft::swap(_size, x._size);
		ft::swap(_capacity, x._capacity);
		ft::swap(_array, x._array);
	}
}
#endif
