/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:33:31 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:55:39 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template< typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	 _size;

	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		Array& operator=(Array const & rhs);
		Array& operator[](unsigned int index);
		const Array& operator[](unsigned int index) const;
		~Array();
		unsigned int	size(void) const;

		class IndexException : public std::exception
		{
			private:
				
			public:
				IndexException() throw() {}
				IndexException(IndexException const &) throw() {}
				virtual ~IndexException() throw() {}
				IndexException & operator=(IndexException const &rhs) throw() {}
				virtual const char* what() const throw() { std::cout << "Index out of range" << std::endl }
		};
};

template< typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template< typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template< typename T>
Array<T>::Array(Array const &src) {

	this->_size = src._size;
	this->_array = new T[this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
}

template< typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template< typename T>
Array<T>& Array<T>::operator=(Array const & rhs)
{
	if (*this == rhs)
		return *this;
	if (this->_array)
		delete [] this->_array;
	this->_size = rhs._size;
	this->_array = new T[this->_size];
	for (int i = 0; i < this->_size; i++)
		this->_array[i] = rhs._array[i];
	return (*this);
}

template< typename T>
Array<T>& Array<T>::operator[](unsigned int index) {

	if (index >= this->_size)
		throw  Array<T>::IndexException();
	return this->_array[index];
}

template< typename T>
const Array<T>& Array<T>::operator[](unsigned int index) const {

	if (index >= this->_size)
		throw Array<T>::IndexException();
	return this->_array[index];
}

template< typename T>
unsigned int	Array<T>::size(void) const { return this->_size }


#endif