/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:03:58 by qperrot-          #+#    #+#             */
/*   Updated: 2020/10/09 11:34:43 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>
#include <limits>
#include "iterator.hpp"

namespace ft {

	template<typename T, typename A = std::allocator<T> >
	class list
	{
		public:
			typedef T value_type;
			typedef A allocator_type;
			typedef typename A::reference reference;
			typedef typename A::const_reference const_reference;
			typedef typename A::difference_type difference_type;
			typedef typename A::size_type size_type;

		private:
			allocator_type _alloc; /* allocator to use for all memory allocations of this container */
			size_type	_size; /* the size of the container */
			Node<T>	*	_end; /* _end->newt = begin and _end->prev = real end */

		public:
			explicit list (const allocator_type& alloc = allocator_type());
			explicit list (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type());
			template <class InputIterator>
  			list (InputIterator first, InputIterator last,
         		const allocator_type& alloc = allocator_type(), typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type Iter = InputIterator());	
			list (const list& x);
			virtual ~list();
			list& operator=( const list& other);
			class iterator;		/* Forward declaration */
			class const_iterator;	
			template <class InputIterator>
  			void 		assign (InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type Iter = InputIterator());
			void 		assign (size_type n, const value_type& val);
			reference	back();
			const_reference	back() const;
			void		clear();
			bool		empty() const;
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			reference	front();
			const_reference	front() const;
			iterator	insert (iterator position, const value_type& val);	
    		void		insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
    		void		insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type Iter = InputIterator());
			size_type	max_size() const;
			void		merge (list& x);
			template <class Compare>
			void		merge (list& x, Compare comp);
			void		pop_back();
			void		pop_front();
			void 		push_back (const value_type& val);
			void		push_front (const value_type& val);
			void		remove (const value_type& val);
			template <class Predicate>
  			void		remove_if (Predicate pred);
			void		resize (size_type n, value_type val = value_type());
			void 		reverse();
			size_type	size() const;
			void		sort();
			template <class Compare>
			void		sort (Compare comp);
			void		splice (iterator position, list& x);
			void		splice (iterator position, list& x, iterator i);
			void		splice (iterator position, list& x, iterator first, iterator last);
			void		swap (list& x);
			void		unique();
			template <class BinaryPredicate>
  			void		unique (BinaryPredicate binary_pred);

			class iterator {
				public:
					typedef typename A::difference_type difference_type;
        			typedef typename A::value_type value_type;
					typedef typename A::reference reference;
					typedef typename A::pointer pointer;
					typedef std::bidirectional_iterator_tag iterator_category;

   				private:
					Node<T> *NodePtr;

				public:
					iterator(Node<T> *newPtr) : NodePtr(newPtr) {}
					iterator() : NodePtr(nullptr) {}
					virtual ~iterator() {};
					
					Node<T> * getNode() const {
						return this->NodePtr;
					}
					/* Overload for the comparison operator == */
					bool operator==(const iterator& itr) const { return this->NodePtr == itr.NodePtr; } 
					/* Overload for the comparison operator != */
					bool operator!=(const iterator& itr) const { return this->NodePtr != itr.NodePtr; } 
					/* Overload for the dereference operator * */
					reference operator*() const { return this->NodePtr->_value; }

					pointer operator->() const { return &(this->NodePtr->_value); }
					/* Overload for the postincrement operator ++ */
					iterator operator++(int) { iterator temp = *this; this->NodePtr = this->NodePtr->_next; return temp; }

					iterator &operator++() { this->NodePtr = this->NodePtr->_next; return *this; }

					iterator operator--(int) { iterator temp = *this; this->NodePtr = this->NodePtr->_prev; return temp; }

					iterator &operator--() { this->NodePtr = this->NodePtr->_prev; return *this; }
			}; /* End of inner class iterator */

			class const_iterator {
				public:
					typedef const T& reference;
					typedef const T* pointer;
					typedef typename A::difference_type difference_type;
					typedef typename A::value_type value_type;
					typedef std::bidirectional_iterator_tag iterator_category;

   				private:
					Node<T> *NodePtr;

				public:
					const_iterator() : NodePtr(nullptr) {} 
					const_iterator(const iterator &other) : NodePtr(other.getNode()) { }
					const_iterator(Node<T> *newPtr) : NodePtr(newPtr) {}
					virtual ~const_iterator() {};

					Node<T> * getNode() const { return this->NodePtr; }

					const_iterator &	operator=(const const_iterator &other) { return (this = &other); }
					/* Overload for the comparison operator != */
					bool operator!=(const const_iterator& itr) const { return this->NodePtr != itr.NodePtr; } 
					/* Overload for the dereference operator * */
					reference operator*() const { return this->NodePtr->_value; }

					pointer operator->() const { return &(this->NodePtr->_value); }
					/* Overload for the postincrement operator ++ */
					const_iterator operator++(int) { const_iterator temp = *this; this->NodePtr = this->NodePtr->_next; return temp; }

					const_iterator &operator++() { this->NodePtr = this->NodePtr->_next; return *this; }

					const_iterator operator--(int) { const_iterator temp = *this; this->NodePtr = this->NodePtr->_prev; return temp; }

					const_iterator &operator--() { this->NodePtr = this->NodePtr->_prev; return *this; }
			};
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;

    		iterator begin() { return iterator(this->_end->_next); }
			
			const_iterator begin() const { return const_iterator(this->_end->_next); }
			
			iterator end() { return iterator(this->_end); }

			const_iterator end() const { return const_iterator(this->_end); }

			reverse_iterator rbegin() { return reverse_iterator(end()); }

			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

			reverse_iterator rend() { return reverse_iterator(begin()); }

			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
	};
	/* Exchanges the contents of two lists (lists Overload) */
	template< class Iterator1, class Iterator2 >
	bool operator==( const  ReverseIterator<Iterator1>& lhs,
					const  ReverseIterator<Iterator2>& rhs ) {return lhs.base() == rhs.base();}
	template< class Iterator1, class Iterator2 >
	bool operator!=( const  ReverseIterator<Iterator1>& lhs,
					const  ReverseIterator<Iterator2>& rhs ) {return lhs.base() != rhs.base();}
	template< class Iterator1, class Iterator2 >
	bool operator<( const  ReverseIterator<Iterator1>& lhs,
					const  ReverseIterator<Iterator2>& rhs ) {return lhs.base() < rhs.base();}
	template< class Iterator1, class Iterator2 >
	bool operator<=( const  ReverseIterator<Iterator1>& lhs,
					const  ReverseIterator<Iterator2>& rhs ) {return lhs.base() <= rhs.base();}
	template< class Iterator1, class Iterator2 >
	bool operator>( const  ReverseIterator<Iterator1>& lhs,
					const  ReverseIterator<Iterator2>& rhs ) {return lhs.base() > rhs.base();}
	template< class Iterator1, class Iterator2 >
	bool operator>=( const  ReverseIterator<Iterator1>& lhs,
					const  ReverseIterator<Iterator2>& rhs ) {return lhs.base() >= rhs.base();}
	
	template< class Iter >
	ReverseIterator<Iter>	operator+( typename ReverseIterator<Iter>::difference_type n,
										const ReverseIterator<Iter>& it ) {return ReverseIterator<Iter>(it.base() - n); }

	template< class Iterator >
	typename ReverseIterator<Iterator>::difference_type operator-( const ReverseIterator<Iterator>& lhs,
    																const ReverseIterator<Iterator>& rhs ) {return (rhs.base() - lhs.base());}

	template<typename T>
	void swap (T &x, T &y) {

		T	tmp(x);

		x = y;
		y = tmp;
	}
	
	template <typename T, typename A >
	void swap (list<T,A>& x, list<T,A>& y) {

		x.swap(y);
	}

	template< typename T, typename A >
	bool operator==( const list<T,A>& lhs, const list<T,A>& rhs ) {

		if (lhs.size() != rhs.size())
			return false;
		typename list<T, A>::const_iterator it = lhs.begin();
		typename list<T, A>::const_iterator it2 = rhs.begin();
		for ( ; it != lhs.end() && it2 != rhs.end() ; ++it, ++it2)
		{
			if (*it != *it2)
				return false;
		}
		return true;
	}

	template< typename T, typename A >
	bool operator!=( const list<T,A>& lhs, const list<T,A>& rhs ) {

		if (!(lhs == rhs))
			return true;
		return false;
	}

	template< typename T, typename A >
	bool operator<( const list<T,A>& lhs, const list<T,A>& rhs ) {

		typename list<T, A>::const_iterator it = lhs.begin();
		typename list<T, A>::const_iterator it2 = rhs.begin();
		for ( ; it != lhs.end() && it2 != rhs.end() ; ++it, ++it2)
		{
			if ((*it != *it2))
				return (*it < *it2);
		}
		if (lhs.size() == rhs.size())
			return false;
		return lhs.size() < rhs.size();
	}

	template< typename T, typename A >
	bool operator<=( const list<T,A>& lhs, const list<T,A>& rhs ) {

		if (!(lhs == rhs))
			return lhs < rhs;
		return true;
	}

	template< typename T, typename A >
	bool operator>( const list<T,A>& lhs, const list<T,A>& rhs ) {

		typename list<T, A>::const_iterator it = lhs.begin();
		typename list<T, A>::const_iterator it2 = rhs.begin();
		for ( ; it != lhs.end() && it2 != rhs.end() ; ++it, ++it2)
		{
			if ((*it != *it2))
				return (*it > *it2);
		}
		if (lhs.size() == rhs.size())
			return false;
		return lhs.size() > rhs.size();
	}

	template< typename T, typename A >
	bool operator>=( const list<T,A>& lhs, const list<T,A>& rhs ) {

		if (!(lhs == rhs))
			return lhs > rhs;
		return true;
	}

	/* Struct Node Creation */
	template<typename T>
	Node<T>::Node(const T &val, Node<T>* next, Node<T>* prev) : _value(val), _next(next), _prev(prev) {}

	/* Class List Constructor */
	template<typename T, typename A>
	list<T, A>::list(const allocator_type& alloc) : _alloc(alloc), _size(0) {

		_end = new Node<T>(value_type(), nullptr, nullptr);
		_end->_next = _end;
		_end->_prev = _end;

	}

	template<typename T, typename A>
	list<T, A>::list(size_type n, const value_type& val,
        const allocator_type& alloc) : _alloc(alloc), _size(n) {

			Node<T> *	current;
			_end = new Node<T>(value_type(), nullptr, nullptr);
			_end->_next = _end;
			_end->_prev = _end;
			current = _end;
			for (size_type i = 0; i < n; i++)
			{
				current->_next = new Node<T>(val, nullptr, current);
				current = current->_next;
			}
			current->_next = _end;
			_end->_prev = current;

	}

	template<typename T, typename A>
	template <class InputIterator>
  	list<T, A>::list(InputIterator first, InputIterator last,
        	const allocator_type& alloc, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type) : _alloc(alloc) {
	
		_end = new Node<T>(value_type(), nullptr, nullptr);
		_end->_next = _end;
		_end->_prev = _end;
		assign(first, last);
	}

	template<typename T, typename A>
	list<T, A>::list(const list& x) : _alloc(x._alloc) {

		Node<T> *	current;
		Node<T> *	Xcurrent;
		_end = new Node<T>(value_type(), nullptr, nullptr);
		_end->_next = _end;
		_end->_prev = _end;
		_size = x._size;
		if (x._size == 0)
			return ;
		current = _end;
		Xcurrent = x._end->_next;
		for (size_type i = 0; i < x._size; i++)
		{
			current->_next = new Node<T>(Xcurrent->_value, nullptr, current);
			current = current->_next;
			Xcurrent = Xcurrent->_next;
		}
		current->_next = _end;
		_end->_prev = current;
	}

	template<typename T, typename A>
	list<T, A>::~list() {
		clear();
		delete _end;
	}

	template<typename T, typename A>
	list<T, A>& list<T, A>::operator=( const list& other) {

		clear();
		insert(begin(), other.begin(), other.end());
		return *this;
	}

	template<typename T, typename A>
	template <class InputIterator>
  	void 		list<T, A>::assign(InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type) {

		clear();
		size_type	num = 0;
		Node<T> *	current = _end;
		while (first != last)
		{
			current->_next = new Node<T>(*first, nullptr, current);
			current = current->_next;
			num++;
			first++;
		}
		current->_next = _end;
		_end->_prev = current;
		_size = num;
	}

	template<typename T, typename A>
	void 		list<T, A>::assign(size_type n, const value_type& val) {

		clear();
		if (n == 0)
			return;
		Node<T> *	current = _end;
		for (size_type i = 0; i < n; i++)
		{
			current->_next = new Node<T>(val, nullptr, current);
			current = current->_next;
		}
		current->_next = _end;
		_end->_prev = current;
		_size = n;
	}

	template<typename T, typename A>
	void 	list<T, A>::clear() {

		Node<T> *	begin = _end->_next;
		Node<T> *	n_begin;
		while (begin != _end)
		{
			n_begin = begin->_next;
			delete begin;
			begin = n_begin;
		}
		_end->_next = _end;
		_end->_prev = _end;
		_size = 0;
	}

	template<typename T, typename A>
	typename list<T, A>::reference	list<T, A>::back() {

		Node<T> *	current;
		current = _end->_next;
		for (size_type i = 1; i < _size; i++)
			current = current->_next;
		return (current->_value);
	}

	template<typename T, typename A>
	typename list<T, A>::const_reference	list<T, A>::back() const {

		Node<T> *	current;
		current = _end->_next;;
		for (size_type i = 1; i < this->_size; i++)
			current = current->_next;
		return (current->_value);
		
	}

	template<typename T, typename A>
	bool		list<T, A>::empty() const {

		if (this->_size == 0)
			return true;
		return false;
	}
	template<typename T, typename A>
	typename list<T, A>::reference	list<T, A>::front() {

		return (this->_end->_next->_value);
	}

	template<typename T, typename A>
	typename list<T, A>::const_reference	list<T, A>::front() const {

		return (this->_end->_next->_value);
	}

	template<typename T, typename A>
	typename list<T, A>::iterator	list<T, A>::insert(iterator position, const value_type& val) {

		insert(position, 1, val);
		--position;
		return (position);
	}

	template<typename T, typename A>
    void		list<T, A>::insert (iterator position, size_type n, const value_type& val) {

		if (n == 0)
			return;

		Node<T> *	current = _end->_next;
		Node<T> *	newNode;
		list<T, A>::iterator it = begin();	
		if (position == it)
		{
			for (size_type i = 0; i < n; i++)
			{
				newNode = new Node<T>(val, current, nullptr);
				current->_prev = newNode;
				if (i == (n - 1))
				{
					newNode->_prev = _end;
					current = current->_prev;
					_size += n;
					_end->_next = newNode;
					break;
				}
				newNode = newNode->_prev;
				current = current->_prev;
			}
			return ;
		}
		list<T, A>::iterator it2 = end();
		if (position == it2)
		{
			Node<T> *	current = _end->_prev;
			for (size_type i = 0; i < n; i++)
			{
				newNode = new Node<T>(val, nullptr, current);
				current->_next = newNode;
				if (i == (n - 1))
				{
					newNode->_next = _end;
					_size += n;
					_end->_prev = newNode;
					break;
				}
				newNode = newNode->_next;
				current = current->_next;
			}
			return ;
		}
		while (position != it)
		{
			current = current->_next;
			it++;
		}
		Node<T> *	prev = current->_prev;
		newNode = new Node<T>(val, nullptr, prev);
		prev->_next = newNode;
		for (size_type i = 1; i < n; i++)
		{
			newNode->_next = new Node<T>(val, nullptr, newNode);
			newNode = newNode->_next;
		}
		newNode->_next = current;
		current->_prev = newNode;
		_size += n;
		return ;
	}

	template<typename T, typename A>
	template <class InputIterator>
    void		list<T, A>::insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type) {

		while (first != last)
		{
			insert(position, *first);
			first++;
		}
	}
	
	template<typename T, typename A>
	typename list<T, A>::iterator	list<T, A>::erase(iterator position) {

	
		Node<T> *	elem = position.getNode();
		elem = elem->_next;
		return erase(position, iterator(elem));
	}
	
	template<typename T, typename A>
	typename list<T, A>::iterator	list<T, A>::erase(iterator first, iterator last) {

		Node<T> *	Nfirst = first.getNode();
		Node<T> *	Nlast = last.getNode();
		Node<T> *	tmp;
		size_type	num = 0;
		Node<T> *	tmp_prev = Nfirst->_prev;

		tmp = Nfirst;
		while(tmp != Nlast)
		{
			Node<T> *	tmp_next = tmp->_next;
			if (tmp != _end)
			{
				delete tmp;
				num++;
			}
			tmp = tmp_next;
		}
		_size -= num;
		tmp_prev->_next = Nlast;
		Nlast->_prev = tmp_prev;
		return iterator(Nlast);
	}

	template<typename T, typename A>
	typename list<T, A>::size_type	list<T, A>::max_size() const {

		return (static_cast<size_type>(std::numeric_limits<ft::list<T, A>::size_type>::max())/ sizeof(Node<T>));
	}


	template<typename T, typename A>
	typename list<T, A>::size_type	list<T, A>::size() const { return this->_size; }

	template<typename T, typename A>
	void		list<T, A>::resize (size_type n, value_type val) {

		if (size() > n)
		{
			while (size() != n)
				erase(iterator(_end->_prev));
		}
		else if (size() < n)
			insert(end(), (n - size()), val);
		return;
	}

	template<typename T, typename A>
	void		list<T, A>::pop_back() {

		Node<T> *	elem = _end->_prev;
		erase(iterator(elem), end());
	}

	template<typename T, typename A>
	void		list<T, A>::pop_front() {

		Node<T> *	elem = _end->_next;
		Node<T> *	elem2 = elem->_next;
		erase(iterator(elem), iterator(elem2)) ;
	}

	template<typename T, typename A>
	void 		list<T, A>::push_back (const value_type& val) {

		insert(end(), val);
	}

	template<typename T, typename A>
	void		list<T, A>::push_front (const value_type& val) {

		insert(begin(), val);
	}

	template<typename T, typename A>
	void		list<T, A>::remove (const value_type& val) {

		for (iterator it = begin(); it!=end() ;)
		{
			if (*it == val)
				it = erase(it);
			else
				++it;
		}
	}

	template<typename T, typename A>
	template <class Predicate>
  	void		list<T, A>::remove_if (Predicate pred) {

		for (iterator it = begin(); it!=end(); ++it)
		{
			if (pred(*it))
				erase(it);
		}
	}

	template<typename T, typename A>
	void 		list<T, A>::reverse() {

		Node<T> *	elem;
		Node<T> *	tmp;
		iterator it = end();
		--it;
		_end->_prev = _end->_next;
		_end->_next = it.getNode();
		for (; it!=end(); ++it)
		{
			elem = it.getNode();
			tmp = elem->_prev;
			elem->_prev = elem->_next;
			elem->_next = tmp;
		}
	}

	template<typename T, typename A>
	void		list<T, A>::sort() {

		Node<T> *	first = _end->_next;
		Node<T> *	second = first->_next;
		while (second != _end)
		{
			if (first->_value > second->_value)
			{
				Node<T>*	nxt = second->_next;
				Node<T>*	prv = first->_prev;
				prv->_next = second;
				second->_prev = prv;
				second->_next = first;
				first->_prev = second;
				first->_next = nxt;
				nxt->_prev = first;
				first = _end->_next;
				second = first->_next;
			}
			else
			{
				first = first->_next;
				second = first->_next;
			}
		}
	}

	template<typename T, typename A>
	template <class Compare>
	void		list<T, A>::sort (Compare comp) {

		Node<T> *	first = _end->_next;
		Node<T> *	second = first->_next;
		while (second != _end)
		{
			if ((first->_value != second->_value) && !(comp(first->_value, second->_value)))
			{
				Node<T>*	nxt = second->_next;
				Node<T>*	prv = first->_prev;
				prv->_next = second;
				second->_prev = prv;
				second->_next = first;
				first->_prev = second;
				first->_next = nxt;
				nxt->_prev = first;
				first = _end->_next;
				second = first->_next;

			}
			else
			{
				first = first->_next;
				second = first->_next;
			}
		}
	}

	template<typename T, typename A>
	void		list<T, A>::splice (iterator position, list& x) {

		Node<T> *	elem = position.getNode();
		iterator	fst = x.begin();
		iterator	lst = x.end();
		--lst;

		Node<T> *	first = fst.getNode();
		Node<T> *	last = lst.getNode();
		Node<T> *	prv = elem->_prev;
		prv->_next = first;
		first->_prev = prv;
		last->_next = elem;
		elem->_prev = last;
		_size += x.size();
		lst = x.end();
		last = lst.getNode();
		last->_next = last;
		last->_prev = last;
		x._size = 0;
	}

	template<typename T, typename A>
	void		list<T, A>::splice (iterator position, list& x, iterator i) {

		Node<T> *	me = position.getNode();
		Node<T> *	elem = i.getNode();
		Node<T> *	nxt = me->_prev;
		Node<T> *	prv = elem->_prev;

		nxt->_next = elem;
		prv->_next = elem->_next;
		elem->_next->_prev = prv;
		elem->_prev = nxt;
		elem->_next = me;
		me->_prev = elem;
		(x._size)--;
		_size++;
	}

	template<typename T, typename A>
	void		list<T, A>::splice (iterator position, list& x, iterator first, iterator last) {

		Node<T> *	me = position.getNode();
		Node<T> *	elem = first.getNode();
		--last;
		Node<T> *	lst = last.getNode();
		Node<T> *	nxt_me = me->_prev;
		Node<T> *	prv_el = elem->_prev;
		Node<T> *	nxt_lst = lst->_next;
		size_type	x_size = x.size();

		nxt_me->_next = elem;
		elem->_prev = nxt_me;
		prv_el->_next = nxt_lst;
		nxt_lst->_prev = prv_el;
		lst->_next = me;
		me->_prev = lst;
		x._size = 0;
		for (iterator i = x.begin(); i != x.end(); i++)
			x._size++;
		_size += (x_size - x._size);
	}

	template<typename T, typename A>
	void 	list<T, A>::swap (list& x) {

		ft::swap(_alloc, x._alloc);
		ft::swap(_end, x._end);
		ft::swap(_size, x._size);
	}

	template<typename T, typename A>
	void		list<T, A>::unique() {

		iterator it = begin();
		++it;
		for (iterator it2 = it ; it2!=end() ;)
		{
			iterator tmp = it2;
			--tmp;
			if (*tmp == *it2)
				it2 = erase(it2);
			else
				++it2;
		}
	}

	template<typename T, typename A>
	template <class BinaryPredicate>
  	void	list<T, A>::unique (BinaryPredicate binary_pred) {
		
		iterator it = begin();
		++it;
		for (iterator it2 = it ; it2!=end() ;)
		{
			iterator tmp = it2;
			--tmp;
			if (binary_pred(*tmp, *it2))
				it2 = erase(it2);
			else
				++it2;
		}
	}

	template<typename T, typename A>
	void		list<T, A>::merge (list& x) {

		if (this == &x)
			return ;

		iterator it = x.begin();
		iterator it2 = begin();
		for (it2 = begin() ; it2!=end() ; ++it2)
		{
			if (it == x.end())
				return;
			if (*it < *it2)
			{
				iterator tmp = it;
				while (tmp != x.end() && *tmp < *it2)
					++tmp;
				splice(it2, x, it, tmp);
				it = tmp;
			}
		}
		if (!x.empty())
			splice(it2, x);
	}

	template<typename T, typename A>
	template <class Compare>
	void		list<T, A>::merge (list& x, Compare comp) {

		if (this == &x)
			return ;

		iterator it = x.begin();
		iterator it2 = begin();
		for (it2 = begin() ; it2!=end() ; ++it2)
		{
			if (it == x.end())
				return;
			if (comp(*it, *it2))
			{
				iterator tmp = it;
				while (tmp != x.end() && comp(*tmp, *it2))
					++tmp;
				splice(it2, x, it, tmp);
				it = tmp;
			}
		}
		if (!x.empty())
			splice(it2, x);
	}

	
}

#endif