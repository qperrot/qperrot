/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:38:30 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/25 15:52:23 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() {

	for (int i = 0; i < 4; i++)
		this->_Source[i] = NULL;
	
}

MateriaSource::MateriaSource(MateriaSource const &src) {

	*this = src;
}

MateriaSource::~MateriaSource() {

	for (int i = 0; i < 4; i++)
		if (this->_Source[i] != NULL)
			delete this->_Source[i];
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs) {

	if (this == &rhs)
		return *this;
	for (int i = 0; i < 4; i++)
		this->_Source[i] = rhs._Source[i];
	return *this;
}

void MateriaSource::learnMateria(AMateria* rhs) {

	for (int i = 0; i < 4; i++) {
		if (this->_Source[i] == NULL)
		{
			this->_Source[i] = rhs;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {

	for (int i = 0; i < 4; i++)
	{
		if (this->_Source[i] != NULL && this->_Source[i]->getType() == type)
			return this->_Source[i]->clone();
	}
	return NULL;
}