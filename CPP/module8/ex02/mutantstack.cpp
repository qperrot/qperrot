/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:11:27 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/17 11:10:11 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template< typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template< typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src) {}

template< typename T>
MutantStack<T>::~MutantStack() {}

template< typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const & rhs) { this->c = rhs.c; return (*this); }

template< typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) { return (this->c.begin()); }

template< typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) { return (this->c.end()); }