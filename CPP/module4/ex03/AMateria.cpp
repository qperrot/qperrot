/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:49:32 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/25 15:58:52 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


AMateria::AMateria(std::string const & type) : _type(type), _xp(0) {

	return ;
}

AMateria::AMateria(AMateria const & rhs) {

	_type = rhs.getType();
	_xp = rhs.getXP();
}

AMateria::~AMateria() {

}

AMateria &	AMateria::operator=(AMateria const & rhs) {

	if (this == &rhs)
		return *this;
	this->_xp = rhs.getXP();
	return *this;
}

std::string const & AMateria::getType() const {

	return this->_type;	
}

unsigned int AMateria::getXP() const {

	return this->_xp;
}

void	AMateria::use(ICharacter& target) {

	(void) target;
	this->_xp += 10;
}