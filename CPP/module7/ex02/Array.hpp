/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:33:31 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/17 15:02:13 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>

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
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		~Array();
		unsigned int	size(void) const;

		class IndexException : public std::exception
		{
			public:
				IndexException() throw();
				IndexException(IndexException const &) throw();
				virtual ~IndexException() throw();
				IndexException & operator=(IndexException const &rhs) throw();
				virtual const char* what() const throw();
		};
};

template< typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template< typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template< typename T>
Array<T>::Array(Array<T> const &src) : _array(new T[src._size]), _size(src._size){

	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
}

template< typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template< typename T>
Array<T>& Array<T>::operator=(Array<T> const & rhs)
{
	if (this->_array)
		delete [] this->_array;
	this->_size = rhs._size;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = rhs._array[i];
	return (*this);
}

template< typename T>
T& Array<T>::operator[](unsigned int index) {

	if (index >= this->_size)
		throw  Array<T>::IndexException();
	return this->_array[index];
}

template< typename T>
const T& Array<T>::operator[](unsigned int index) const {

	if (index >= this->_size)
		throw Array::IndexException();
	return this->_array[index];
}

template< typename T>
unsigned int	Array<T>::size(void) const { return this->_size; }

template< typename T>
Array<T>::IndexException::IndexException() throw() {}

template< typename T>
Array<T>::IndexException::IndexException(Array<T>::IndexException const &rhs) throw() { *this = rhs;}

template< typename T>
Array<T>::IndexException::~IndexException() throw() {}

template< typename T>
typename Array<T>::IndexException& Array<T>::IndexException::operator=(Array<T>::IndexException const &rhs) throw() { (void)rhs; return (*this); }

template< typename T>
const char* Array<T>::IndexException::what() const throw() { return ("Index out of range"); }

#endif