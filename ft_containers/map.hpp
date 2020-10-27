/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:23:19 by qperrot-          #+#    #+#             */
/*   Updated: 2020/10/27 09:24:27 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include <limits>
#include "iterator.hpp"
#include "list.hpp"
#include <utility>

enum Color {Black, Red};

namespace ft {
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2	second_type;
		T1			first;
		T2			second;

		public:
			pair() : first(), second() {}
			pair( const T1& x, const T2& y ) : first(x), second(y) {}
			template< class U1, class U2 >
			pair( const pair<U1,U2>& p ) : first(p.first), second(p.second) {}
			~pair() {}

			pair& operator=( const pair& other )
			{
				first = other.first;
				second = other.second;
				return *this;
			}
			template< class U1, class U2 >
			pair& operator=( const pair<U1,U2>& other )
			{
				first = other.first;
				second = other.second;
				return *this;
			}
	};

	template <class T1, class T2>
	pair<T1,T2> make_pair( T1 t, T2 u ) {
	
		return pair<T1, T2>(t, u);
	}

	template<class T1, class T2>
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		if ((lhs.first == rhs.first) && (lhs.second == rhs.second))
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return lhs == rhs; }

	template< class T1, class T2 >
	bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		if (lhs.first < rhs.first)
			return true;
		else if (rhs.first < lhs.first)
			return false;
		else if (lhs.second < rhs.second)
			return true;
		return false;
	}

	template< class T1, class T2 >
	bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return !(rhs < lhs);}

	template< class T1, class T2 >
	bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return rhs < lhs;}

	template< class T1, class T2 >
	bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return !(lhs < rhs);}

	template< class T >
	struct less
	{
		typedef bool	result_type;
		typedef T 		first_argument_type;
		typedef T		second_argument_type;

		bool operator()( const T& lhs, const T& rhs ) const {
			if (lhs < rhs)
				return true;
			return false;
		}
	};

}

namespace ft {
	template<typename T, typename Key, typename value_type>
	struct BTreeNode
	{
		value_type						_pair;
		BTreeNode<T, Key, value_type>	*_parent;
		BTreeNode<T, Key, value_type>	*_left;
		BTreeNode<T, Key, value_type>	*_right;
		Color							_color;

		public:
			BTreeNode<T, Key, value_type>	*getUncle(BTreeNode<T, Key, value_type> *null)
			{
				BTreeNode<T, Key, value_type> *p = this->_parent;
				if (p == null)
					return null;
				BTreeNode<T, Key, value_type> *gp = this->_parent->_parent;
				if (gp == null)
					return null;
				if (p == gp->_left)
					return gp->_right;
				return gp->_left;
			}

		public:
			BTreeNode(const value_type	&pair, BTreeNode<T, Key, value_type> *parent, BTreeNode<T, Key, value_type> *left, BTreeNode<T, Key, value_type> *right, Color col ) : _pair(pair), _parent(parent), _left(left), _right(right), _color(col) { }
	};
}


namespace ft {

	template< typename Key, typename T, typename Comp = less<Key>, typename A = std::allocator<pair<const Key, T> > > 
	class map
	{
		public:
			typedef Key key_type;
			typedef T	mapped_type;
			typedef pair<const Key, T> value_type;
			typedef std::size_t	size_type;
			typedef std::ptrdiff_t	difference_type;
			typedef Comp key_compare;
			typedef A allocator_type;
			typedef typename A::reference reference;
			typedef typename A::const_reference const_reference;
			typedef typename A::pointer pointer;
			typedef typename A::const_pointer const_pointer;

			class value_compare 
			{ 
				protected:
					Comp _comp;
					value_compare (Comp c) : _comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					value_compare() : _comp() {}
					value_compare(const value_compare& copy) : _comp(copy._comp) {}
					~value_compare() {};
					value_compare& operator=( const value_compare& other ) {
						
						_comp = other._comp;
						return *this;
					}
				
					bool operator() (const value_type& x, const value_type& y) const
					{
						return _comp(x.first, y.first);
					}
			};

		private:
			BTreeNode<T, Key, value_type> 	*_root; /* mutable ? */
			BTreeNode<T, Key, value_type> 	*_end;
			BTreeNode<T, Key, value_type> 	*_null;
			key_compare 					_comp;
			allocator_type 					_alloc;
			size_type						_size;
			void	leftRotation(BTreeNode<T, Key, value_type> *node);
			void	rightRotation(BTreeNode<T, Key, value_type> *node);
			void	fixeRotation(BTreeNode<T, Key, value_type> *node);
			void	fixecolor(BTreeNode<T, Key, value_type> *node);
			void	fixeDelete(BTreeNode<T, Key, value_type> *x);
			void	fixeTree(BTreeNode<T, Key, value_type> *node);
			void	transplant(BTreeNode<T, Key, value_type> *u, BTreeNode<T, Key, value_type> *v)
			{
				if (u->_parent == nullptr)
				{
					_root = v;
					_root->_parent = nullptr;
				}
				else if (u == u->_parent->_left)
					u->_parent->_left = v;
				else
					u->_parent->_right = v;
				v->_parent = u->_parent;
			};
		
		public:
			class iterator;
			class const_iterator;
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
  			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type Iter = InputIterator());	
			map (const map& x);
			virtual ~map();
			map& operator= (const map& x);
			pair<typename map<Key, T, Comp, A>::iterator,bool> insert (const value_type& val);
			iterator insert (iterator position, const value_type& val);
			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type Iter = InputIterator());
			void clear();
			size_type count (const key_type& k) const;
			bool empty() const;
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			pair<iterator,iterator>             equal_range (const key_type& k);
			void erase (iterator position);
			size_type erase (const key_type& k);
	 		void erase (iterator first, iterator last);
			iterator find (const key_type& k);
			const_iterator find (const key_type& k) const;
			key_compare key_comp() const;
			size_type size() const;
			void swap (map& x);
			size_type max_size() const;
			mapped_type& operator[] (const key_type& k);
			value_compare value_comp() const;
			iterator lower_bound (const key_type& k);
			const_iterator lower_bound (const key_type& k) const;
			iterator upper_bound (const key_type& k);
			const_iterator upper_bound (const key_type& k) const;


		class iterator {
				public:
					typedef typename A::difference_type difference_type;
					typedef pair<const Key, T> value_type;
					typedef typename A::reference reference;
					typedef typename A::pointer pointer;
					typedef std::bidirectional_iterator_tag iterator_category;

   				private:
					BTreeNode<T, Key, value_type> 	*_root;
					BTreeNode<T, Key, value_type> 	*_null;

				public:
					iterator(BTreeNode<T, Key, value_type> *newPtr, BTreeNode<T, Key, value_type> *nulptr) : _root(newPtr),  _null(nulptr) {}
					iterator() : _root(nullptr), _null(nullptr) {}
					virtual ~iterator() {};
					
					BTreeNode<T, Key, value_type> * getTree() const {
						return this->_root;
					}

					BTreeNode<T, Key, value_type> * getNull() const {
						return this->_null;
					}
					/* Overload for the comparison operator == */
					bool operator==(const iterator& itr) const {
						if ((this->_root == itr._root) == true && (this->_null == itr._null) == true) 
							return true;
						return false;
					} 
					/* Overload for the comparison operator != */
					bool operator!=(const iterator& itr) const {
						if ((this->_root != itr._root) == true )
							return true;
						return false;
					} 
					/* Overload for the dereference operator * */
					reference operator*() const { return this->_root->_pair; }

					pointer operator->() const { return &(this->_root->_pair); }
					/* Overload for the postincrement operator ++ */
					iterator operator++(int) { iterator temp = *this; ++(*this); return temp; }

					iterator &operator++() {
						
						if (_root->_right != _null && _root->_right != nullptr)
						{
							_root = _root->_right;
							while (_root->_left != _null && _root->_left != nullptr)
							{
								_root = _root->_left;
							}
							return *this;
						}
						if (_root->_right == _null || _root->_right == nullptr)
						{
							if (_root->_parent != nullptr)
							{
								if (_root->_parent->_left == _root)
								{
									_root = _root->_parent;
									return *this;
								}
								while ((_root->_parent != nullptr) &&  (_root->_parent->_pair.first < _root->_pair.first))
								{
									_root = _root->_parent;
								}
								if ((_root->_parent->_pair.first > _root->_pair.first))
								{
									_root = _root->_parent;
									return *this;
								}
								return *this;
							}
							else if ( _root->_parent == nullptr)
							{
								if (_root->_right != _null && _root->_right != nullptr)
									_root = _root->_right;
								while (_root->_left != _null && _root->_left != nullptr)
								{
									_root = _root->_left;
								}
								return *this;
							}
						}
						return *this;
					}

					iterator operator--(int) { iterator temp = *this; --(*this); return temp; }

					iterator &operator--() {

						if (_root->_left != _null && _root->_left != nullptr)
						{
							_root = _root->_left;
							while (_root->_right != _null && _root->_right != nullptr)
							{
								_root = _root->_right;
							}
							return *this;
						}
						if (_root->_left == _null || _root->_left == nullptr)
						{
							if (_root->_parent != nullptr)
							{
								if (_root->_parent->_right == _root)
								{
									_root = _root->_parent;
									return *this;
								}
								while ((_root->_parent != nullptr) &&  (_root->_parent->_pair.first > _root->_pair.first))
								{
									_root = _root->_parent;
								}
								if ((_root->_parent->_pair.first < _root->_pair.first))
								{
									_root = _root->_parent;
									return *this;
								}
								return *this;
							}
							else if ( _root->_parent == nullptr)
							{
								if (_root->_left != _null && _root->_left != nullptr)
									_root = _root->_left;
								while (_root->_right != _null && _root->_right != nullptr)
								{
									_root = _root->_right;
								}
								return *this;
							}
						}
						return *this;
					}
			}; /* End of inner class iterator */

			class const_iterator {
				public:
					typedef typename A::difference_type difference_type;
					typedef pair<const Key, T> value_type;
					typedef typename A::reference reference;
					typedef typename A::pointer pointer;
					typedef std::bidirectional_iterator_tag iterator_category;

   					private:
					BTreeNode<T, Key, value_type> 	*_root;
					BTreeNode<T, Key, value_type> 	*_null;

				public:
					const_iterator(BTreeNode<T, Key, value_type> *newPtr, BTreeNode<T, Key, value_type> *nulptr ) : _root(newPtr), _null(nulptr) {}
					const_iterator(const iterator &other) : _root(other.getTree()), _null(other.getNull()) { }
					const_iterator() : _root(nullptr), _null(nullptr) {}
					virtual ~const_iterator() {};
					
					BTreeNode<T, Key, value_type> * getTree() const {
						return this->_root;
					}

					BTreeNode<T, Key, value_type> * getNull() const {
						return this->_null;
					}
					/* Overload for the comparison operator == */
					bool operator==(const const_iterator& itr) const { 
						if ((this->_root == itr._root) == true && (this->_null == itr._null) == true) 
							return true;
						return false; } 
					/* Overload for the comparison operator != */
					bool operator!=(const const_iterator& itr) const { 
						if ((this->_root != itr._root) == true ) 
							return true;
						return false;
					} 
					/* Overload for the dereference operator * */
					reference operator*() const { return this->_root->_pair; }

					pointer operator->() const { return &(this->_root->_pair); }
					/* Overload for the postincrement operator ++ */
					const_iterator operator++(int) { const_iterator temp = *this; ++(*this); return temp; }

					const_iterator &operator++() {

						if (_root->_right != _null && _root->_right != nullptr)
						{
							_root = _root->_right;
							while (_root->_left != _null && _root->_left != nullptr)
							{
								_root = _root->_left;
							}
							return *this;
						}
						if (_root->_right == _null || _root->_right == nullptr)
						{
							if (_root->_parent != nullptr)
							{
								if (_root->_parent->_left == _root)
								{
									_root = _root->_parent;
									return *this;
								}
								while ((_root->_parent != nullptr) &&  (_root->_parent->_pair.first < _root->_pair.first))
								{
									_root = _root->_parent;
								}
								if ((_root->_parent->_pair.first > _root->_pair.first))
								{
									_root = _root->_parent;
									return *this;
								}
								return *this;
							}
							else if ( _root->_parent == nullptr)
							{
								if (_root->_right != _null && _root->_right != nullptr)
									_root = _root->_right;
								while (_root->_left != _null && _root->_left != nullptr)
								{
									_root = _root->_left;
								}
								return *this;
							}
						}
						return *this;
					}

					const_iterator operator--(int) { const_iterator temp = *this; --(*this); return temp; }

					const_iterator &operator--() {

						if (_root->_left != _null && _root->_left != nullptr)
						{
							_root = _root->_left;
							while (_root->_right != _null && _root->_right != nullptr)
							{
								_root = _root->_right;
							}
							return *this;
						}
						if (_root->_left == _null || _root->_left == nullptr)
						{
							if (_root->_parent != nullptr)
							{
								if (_root->_parent->_right == _root)
								{
									_root = _root->_parent;
									return *this;
								}
								while ((_root->_parent != nullptr) &&  (_root->_parent->_pair.first > _root->_pair.first))
								{
									_root = _root->_parent;
								}
								if ((_root->_parent->_pair.first < _root->_pair.first))
								{
									_root = _root->_parent;
									return *this;
								}
								return *this;
							}
							else if ( _root->_parent == nullptr)
							{
								if (_root->_left != _null && _root->_left != nullptr)
									_root = _root->_left;
								while (_root->_right != _null && _root->_right != nullptr)
								{
									_root = _root->_right;
								}
								return *this;
							}
						}
						return *this;
					}
			};
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;

			iterator begin() {
				BTreeNode<T, Key, value_type> *tmp = _root;
				while (tmp->_left != _null && tmp->_left != nullptr)
					tmp = tmp->_left;
				return iterator(tmp, _null); }
			
			const_iterator begin() const {
				BTreeNode<T, Key, value_type> *tmp = _root;
				while (tmp->_left != _null && tmp->_left != nullptr)
					tmp = tmp->_left;
				return const_iterator(tmp, _null); }
			
			iterator end() {
				return iterator(_end, _null); }
			
			const_iterator end() const {
				return const_iterator(_end, _null); } 

			reverse_iterator rbegin() { return reverse_iterator(end()); }

			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

			reverse_iterator rend() { return reverse_iterator(begin()); }

			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
	};
	
	template< typename Key, typename T, typename value_type >
	BTreeNode<T, Key, value_type> *minimum(BTreeNode<T, Key, value_type> *node, BTreeNode<T, Key, value_type> *null )
	{
		while (node->_left != null)
			node = node->_left;
		return node;
	}

	template< typename Key, typename T, typename Comp, typename A >
	void	map<Key, T, Comp, A>::leftRotation(BTreeNode<T, Key, value_type> *node)
	{
		BTreeNode<T, Key, value_type> *tmp = node->_right;
		node->_right = tmp->_left;
		if (tmp->_left != _null)
			tmp->_left->_parent = node;

		tmp->_parent = node->_parent;
		if (node->_parent == nullptr)
			_root = tmp;
		else if ( node == node->_parent->_left)
			node->_parent->_left = tmp;
		else
			node->_parent->_right = tmp;

		tmp->_left = node;
		node->_parent = tmp;
	}

	template< typename Key, typename T, typename Comp, typename A > 
	void	map<Key, T, Comp, A>::rightRotation(BTreeNode<T, Key, value_type> *node)
	{
		BTreeNode<T, Key, value_type> *tmp = node->_left;

		node->_left = tmp->_right;
		if (tmp->_right != _null)
			tmp->_right->_parent = node;

		tmp->_parent = node->_parent;

		if (node->_parent == nullptr)
			_root = tmp;
		else if ( node == node->_parent->_right)
			node->_parent->_right = tmp;
		else
			node->_parent->_left = tmp;

		tmp->_right = node;
		node->_parent = tmp;
		
	}
	
	 template< typename Key, typename T, typename Comp, typename A >
	void	map<Key, T, Comp, A>::fixeRotation(BTreeNode<T, Key, value_type> *node)
	{
		BTreeNode<T, Key, value_type> *p = node->_parent;
		BTreeNode<T, Key, value_type> *gp = node->_parent->_parent;

		if (gp->_left != _null && gp->_left != nullptr && node == gp->_left->_right)
		{
			leftRotation(p);
			node = node->_left;
		}
		else if (gp->_right != _null && gp->_right != nullptr && node == gp->_right->_left)
		{
			rightRotation(p);
			node = node->_right;
		}
		p = node->_parent;
		gp = node->_parent->_parent;
		if (node == p->_left)
			rightRotation(gp);
		else
			leftRotation(gp);

		p->_color = Black;
		gp->_color = Red;
		
	}
	
	template< typename Key, typename T, typename Comp, typename A >
	void	map<Key, T, Comp, A>::fixecolor(BTreeNode<T, Key, value_type> *node)
	{
		node->_parent->_color = Black;
		(node->getUncle(_null))->_color = Black;
		BTreeNode<T, Key, value_type> *gp = node->_parent->_parent;
		gp->_color = Red;
		fixeTree(gp);
	}

	template< typename Key, typename T, typename Comp, typename A >
	void	map<Key, T, Comp, A>::fixeDelete(BTreeNode<T, Key, value_type> *x)
	{

		BTreeNode<T, Key, value_type> *s;
		while (x != _root && x->_color == Black)
		{
			if (x == x->_parent->_left) 
			{
	   			s = x->_parent->_right;
				if (s->_color == Red) 
				{
		 			s->_color = Black;
		 			x->_parent->_color = Red;
		 			leftRotation(x->_parent);
		  			s = x->_parent->_right;
				}

				if (s->_left->_color == Black && s->_right->_color == Black)
				{
		  			s->_color = Red;
		 			x = x->_parent;
				}
				else 
				{
		  			if (s->_right->_color == Black)
					{
						s->_left->_color = Black;
						s->_color = Red;
						rightRotation(s);
						s = x->_parent->_right;
		  			}

					s->_color = x->_parent->_color;
					x->_parent->_color = Black;
					s->_right->_color = Black;
					leftRotation(x->_parent);
					x = _root;
				}
	  		}
			else 
			{
				s = x->_parent->_left;
				if (s->_color == Red)
				{
					s->_color = Black;
					x->_parent->_color = Red;
					rightRotation(x->_parent);
					s = x->_parent->_left;
				}

				if (s->_right->_color == Black && s->_right->_color == Black)
				{
					s->_color = Red;
					x = x->_parent;
				} 
				else
				{
					if (s->_left->_color == Black) 
					{
		   				s->_right->_color = Black;
						s->_color = Red;
						leftRotation(s);
						s = x->_parent->_left;
		  			}
					
					s->_color = x->_parent->_color;
					x->_parent->_color = Black;
					s->_left->_color = Black;
					rightRotation(x->_parent);
					x = _root;
				}
			}
		}
		x->_color = Black;
  	}
	
	template< typename Key, typename T, typename Comp, typename A >
	void	map<Key, T, Comp, A>::fixeTree(BTreeNode<T, Key, value_type> *node)
	{
		if (node->_parent == nullptr)
			node->_color = Black;
		else if (node->_parent->_color == Black)
			return ;
		else if (node->getUncle(_null) != _null && node->getUncle(_null) != nullptr && (node->getUncle(_null))->_color == Red)
			fixecolor(node);
		else
			fixeRotation(node);		
	}

	template< typename Key, typename T, typename Comp, typename A > 
	map<Key, T, Comp, A>& map<Key, T, Comp, A>::operator= (const map& x) {

		clear();
		insert(x.begin(), x.end());
	}

	template< typename Key, typename T, typename Comp, typename A >
	bool operator== ( const map<Key,T,Comp,A>& lhs, const map<Key,T,Comp,A>& rhs ){
		
		if (lhs.size() != rhs.size())
		return false;
		typename map<Key, T>::const_iterator it = lhs.begin();
		typename map<Key, T>::const_iterator it2 = rhs.begin();
		for ( ; it != lhs.end() && it2 != rhs.end() ; ++it, ++it2)
		{
			if (it->first != it2->first)
				return false;
			if (it->second != it2->second)
				return false;
		}
		return true;
	}

	template< typename Key, typename T, typename Comp, typename A >
	bool operator!= ( const map<Key,T,Comp,A>& lhs, const map<Key,T,Comp,A>& rhs ){

		if (!(lhs == rhs))
			return true;
		return false;
	}

	template< typename Key, typename T, typename Comp, typename A >
	bool operator<  ( const map<Key,T,Comp,A>& lhs, const map<Key,T,Comp,A>& rhs ){

		typename map<Key, T>::const_iterator it = lhs.begin();
		typename map<Key, T>::const_iterator it2 = rhs.begin();
		for ( ; it != lhs.end() && it2 != rhs.end() ; ++it, ++it2)
		{
			if (it->first != it2->first)
				return (it->first < it2->first);
			if (it->second != it2->second)
				return (it->second < it2->second);
		}
		if (lhs.size() == rhs.size())
			return false;
		return lhs.size() < rhs.size();
	}

	template< typename Key, typename T, typename Comp, typename A >
	bool operator<= ( const map<Key,T,Comp,A>& lhs, const map<Key,T,Comp,A>& rhs ){

		if (!(lhs == rhs))
			return lhs < rhs;
		return true;
	}

	template< typename Key, typename T, typename Comp, typename A >
	bool operator>  ( const map<Key,T,Comp,A>& lhs, const map<Key,T,Comp,A>& rhs ){

		typename map<Key, T>::const_iterator it = lhs.begin();
		typename map<Key, T>::const_iterator it2 = rhs.begin();
		for ( ; it != lhs.end() && it2 != rhs.end() ; ++it, ++it2)
		{
			if (it->first != it2->first)
				return (it->first > it2->first);
			if (it->second != it2->second)
				return (it->second > it2->second);
		}
		if (lhs.size() == rhs.size())
			return false;
		return lhs.size() > rhs.size();
	}

	template< typename Key, typename T, typename Comp, typename A >
	bool operator>= ( const map<Key,T,Comp,A>& lhs, const map<Key,T,Comp,A>& rhs ){

		if (!(lhs == rhs))
			return lhs > rhs;
		return true;
	}

	template< typename Key, typename T, typename Comp, typename A >
  	void swap (map<Key,T,Comp,A>& x, map<Key,T,Comp,A>& y) {
		
		x.swap(y);
	}
  
	template< typename Key, typename T, typename Comp, typename A >  
	map<Key, T, Comp, A>::map (const key_compare& comp, const allocator_type& alloc) : _comp(comp), _alloc(alloc), _size(0) {
		_end =  new BTreeNode<T, Key, value_type>(value_type(), nullptr, nullptr, nullptr, Black);
		_null =  new BTreeNode<T, Key, value_type>(value_type(), nullptr, nullptr, nullptr, Black);
		_root = _end;
	}

	template< typename Key, typename T, typename Comp, typename A > 
	template <class InputIterator>
  	map<Key, T, Comp, A>::map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc,  typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type) : _comp(comp), _alloc(alloc), _size(0) {

		_end =  new BTreeNode<T, Key, value_type>(value_type(), nullptr, nullptr, nullptr, Black);
		_null =  new BTreeNode<T, Key, value_type>(value_type(), nullptr, nullptr, nullptr, Black);
		_root = _end;
		insert(first, last);
	}	
	
	template< typename Key, typename T, typename Comp, typename A > 
	map<Key, T, Comp, A>::map(const map& x) : _comp(x._comp), _alloc(x._alloc) {

		_end =  new BTreeNode<T, Key, value_type>(value_type(), nullptr, nullptr, nullptr, Black);
		_null =  new BTreeNode<T, Key, value_type>(value_type(), nullptr, nullptr, nullptr, Black);
		_root = _end;
		_size = 0;
		if (x._size == 0)
		{
			_size = 0;
			return;
		}
		insert(x.begin(), x.end());
	}

	template< typename Key, typename T, typename Comp, typename A >  
	map<Key, T, Comp, A>::~map()
	{
		clear();
		delete _end;
		delete _null;
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::mapped_type& map<Key, T, Comp, A>::operator[] (const key_type& k) {

		return (*((this->insert(make_pair(k,mapped_type()))).first)).second;		
	}

	template< typename Key, typename T, typename Comp, typename A >
	template <class InputIterator>
	void map<Key, T, Comp, A>::insert(InputIterator first, InputIterator last, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type) {

		while (first != last)
		{
			insert((*first));
			first++;
		}
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::iterator map<Key, T, Comp, A>::insert (iterator position, const value_type& val) {
		
		if (find(val.first) == end())
		{
			if ((position.getTree())->_pair.first < val.first)
			{
				iterator upper = upper_bound(val.first);
				if (upper_bound((position.getTree())->_pair.first) == upper_bound(val.first))
				{
					if (_root == _end)
					{
						insert(val);
						return (find(val.first));
					}
					BTreeNode<T, Key, value_type> 	*right = (position.getTree())->_right;
					(position.getTree())->_right = new BTreeNode<T, Key, value_type>(val, (position.getTree()), _null, right, Red);
					if (right != _null && right != nullptr)
					{
						right->_parent = (position.getTree())->_right;
					}
					fixeTree((position.getTree())->_right);
					_size++;
					_root = (position.getTree())->_right;
					while ( _root->_parent != nullptr)
						_root = _root->_parent;
					return ++position;
				}
				insert(val);
			}
			insert(val);
		}
		return (find(val.first));

	}
	
	template< typename Key, typename T, typename Comp, typename A >  
	typename ft::pair<typename map<Key, T, Comp, A>::iterator,bool> map<Key, T, Comp, A>::insert (const value_type& val) {

		if (_root == _end)
		{
			_root = new BTreeNode<T, Key, value_type>(val, nullptr, _null, _end, Black);
			_end->_parent = _root;
			_null->_parent = _root;
			_size++;
			return (pair<iterator, bool>(iterator(_root, _null), true));
		}
		for (iterator it=begin(); it!=end(); ++it)
		{
			if ((it.getTree())->_pair.first == val.first)
				return (pair<iterator, bool>(it, false));
		}
		BTreeNode<T, Key, value_type> 	*newroot = _root;
		BTreeNode<T, Key, value_type> 	*tmp = newroot;
		while ( newroot != _null && newroot != _end)
		{
			tmp = newroot;
			if (newroot->_pair.first > val.first)
			{
				newroot = newroot->_left;
			}
			else if (newroot->_pair.first < val.first)
			{
				newroot = newroot->_right;
			}
		}
		if (newroot == _end)
		{
			newroot = tmp;
			newroot->_right = new BTreeNode<T, Key, value_type>(val, newroot, _null, _end, Red);
			_end->_parent = newroot->_right;
			tmp = newroot->_right;
			_size++;
			fixeTree(tmp);
			_root = tmp;
			while ( _root->_parent != nullptr)
				_root = _root->_parent;
			return (pair<iterator, bool>(iterator(tmp, _null), true));
		}
		newroot = tmp;
		if (newroot->_pair.first > val.first)
		{
			newroot->_left = new BTreeNode<T, Key, value_type>(val, newroot, _null, _null, Red);
			tmp = newroot->_left;
		}
		else if (newroot->_pair.first < val.first)
		{
			newroot->_right = new BTreeNode<T, Key, value_type>(val, newroot,  _null,  _null, Red);
			tmp = newroot->_right;
		}
		_size++;
		fixeTree(tmp);
		_root = tmp;
		while ( _root->_parent != nullptr)
			_root = _root->_parent;
		return (pair<iterator, bool>(iterator(tmp, _null), true));
	}
	
	template< typename Key, typename T, typename Comp, typename A >
	void map<Key, T, Comp, A>::clear() {
		
		
		erase(begin(), end());
		_size = 0;
		_end->_parent = nullptr;
		_root = _end;
	}

	template< typename Key, typename T, typename Comp, typename A >
	void map<Key, T, Comp, A>::erase (iterator first, iterator last) {

		ft::list<Key> tmp;
		for (iterator it=first; it != last; it++)
			tmp.push_back((*it).first);
		for (typename ft::list<Key>::iterator it=tmp.begin(); it != tmp.end(); it++)
			erase(*it);
	}

	template< typename Key, typename T, typename Comp, typename A >
	void map<Key, T, Comp, A>::erase (iterator position) {
		
		erase((*position).first);
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::size_type map<Key, T, Comp, A>::erase (const key_type& k) {
		
		BTreeNode<T, Key, value_type> 	*z = _null;
		BTreeNode<T, Key, value_type> 	*x, *y;
		BTreeNode<T, Key, value_type> 	*node = _root;

		if (node->_right == _end && node->_left == _null)
		{
			delete node;
			_size--;
			return 1;
		}
		while (node != _null && node != nullptr)
		{
			if (node->_pair.first == k)
				z = node;
			if (node->_pair.first <= k)
				node = node->_right;
			else
				node = node->_left;
		}
		if (z == _null || z == nullptr)
			return 0;

		y = z;
		Color y_origin_col = y->_color;
		if (z->_left == _null)
		{
			x = z->_right;
			transplant(z, z->_right);
		}
		else if (z->_right == _null || z->_right == _end)
		{
			if (z->_right == _end)
			{
				x = z->_left;
				transplant(z, z->_left);
				BTreeNode<T, Key, value_type> 	*tmp = _root;
				while (tmp->_right != _null)
					tmp = tmp->_right;
				tmp->_right = _end;
				_end->_parent = tmp;
			}
			else
			{
				x = z->_left;
				transplant(z, z->_left);
			}			
		}
		else
		{
			y = minimum(z->_right, _null);	
			y_origin_col = y->_color;
			x = y->_right;
			if (y->_parent == z)
			{
				x->_parent = y;
			}
			else
			{
				transplant(y, y->_right);
				y->_right = z->_right;
				y->_right->_parent = y;
			}
			transplant(z, y);
			y->_left = z->_left;
			y->_left->_parent = y;
			y->_color = z->_color;
		}
		delete z;
		if (y_origin_col == Black)
		{
			fixeDelete(x);
		}
		_size--;
		return 1;
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::size_type map<Key, T, Comp, A>::count (const key_type& k) const {
		
		for (const_iterator it=begin(); it!=end(); ++it)
		{
			if ((it.getTree())->_pair.first == k )
				return 1;
		}
		return 0;
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::key_compare map<Key, T, Comp, A>::key_comp() const {
		
		return key_compare();
	}
	template< typename Key, typename T, typename Comp, typename A >
	bool map<Key, T, Comp, A>::empty() const { 
		if (_size == 0) 
			return true; 
		return false; 
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::iterator map<Key, T, Comp, A>::find (const key_type& k) {

		if (count(k) == 1)
		{
			for (iterator it=begin(); it!=end(); ++it)
			{
				if ((it.getTree())->_pair.first == k )
					return it;
			}
		}
		return end();
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::const_iterator map<Key, T, Comp, A>::find (const key_type& k) const {
		
		if (count(k) == 1)
		{
			for (const_iterator it=begin(); it!=end(); ++it)
			{
				if ((it.getTree())->_pair.first == k )
					return it;
			}
		}
		return end();
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename ft::pair<typename map<Key, T, Comp, A>::const_iterator, typename map<Key, T, Comp, A>::const_iterator>	map<Key, T, Comp, A>::equal_range (const key_type& k) const {
		
	return pair<const_iterator, const_iterator>(const_iterator(lower_bound(k)), const_iterator(upper_bound(k)));
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename ft::pair<typename map<Key, T, Comp, A>::iterator, typename map<Key, T, Comp, A>::iterator>	map<Key, T, Comp, A>::equal_range (const key_type& k) {
		
		return pair<iterator, iterator>(iterator(lower_bound(k)), iterator(upper_bound(k)));
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::iterator  map<Key, T, Comp, A>::lower_bound (const key_type& k) {

		for (iterator it=begin(); it!=end(); ++it)
		{
			if ((it.getTree())->_pair.first >= k )
				return it;
		}
		return end();
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::const_iterator  map<Key, T, Comp, A>::lower_bound (const key_type& k) const {

		for (const_iterator it=begin(); it!=end(); ++it)
		{
			if ((it.getTree())->_pair.first >= k )
				return it;
		}
		return end();
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::iterator  map<Key, T, Comp, A>::upper_bound (const key_type& k) {

		for (iterator it=begin(); it!=end(); ++it)
		{
			if ((it.getTree())->_pair.first > k )
				return it;
		}
		return end();
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::const_iterator  map<Key, T, Comp, A>::upper_bound (const key_type& k) const {

		for (const_iterator it=begin(); it!=end(); ++it)
		{
			if ((it.getTree())->_pair.first > k )
				return it;
		}
		return end();
	}

	template< typename Key, typename T, typename Comp, typename A >
	void map<Key, T, Comp, A>::swap(map& x) {
		
		ft::swap(_alloc, x._alloc);
		ft::swap(_comp, x._comp);
		ft::swap(_end, x._end);
		ft::swap(_null, x._null);
		ft::swap(_root, x._root);
		ft::swap(_size, x._size);
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::size_type map<Key, T, Comp, A>::size() const { return _size; }

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::size_type map<Key, T, Comp, A>::max_size() const {
		
		return (static_cast<size_type>(std::numeric_limits<ft::map<Key, T, Comp, A>::size_type>::max())/ sizeof(BTreeNode<T, Key, value_type>));
	}

	template< typename Key, typename T, typename Comp, typename A >
	typename map<Key, T, Comp, A>::value_compare map<Key, T, Comp, A>::value_comp() const {

		return value_compare();	
	}
}

#endif
