/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:45:43 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/19 17:53:07 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string name) : _Nom(name)
{
	std::cout << "A random victim called " << this->_Nom << " just appeared!" << std::endl;
}

Victim::Victim(Victim const & src)
{
	*this = src;
	std::cout << "A random victim called " << this->_Nom << " just appeared!" << std::endl;
	return ;
}

Victim::~Victim()
{
	std::cout << "The victim " << this->_Nom << " died for no apparent reasons!" << std::endl;
}

std::string		Victim::getName( void ) const {

	return (this->_Nom);
}

std::ostream &	operator<<(std::ostream & o, Victim const & rhs) {

	o << "I 'm ";
	o << rhs.getName();
	o << " and I like otters!";
	o << std::endl;
	return o;
}

Victim &	Victim::operator=(Victim const & rhs) {

	this->_Nom = rhs.getName();
	return *this;
}

void		Victim::getPolymorphed() const {

	std::cout << this->_Nom << " was just polymorphed in a cute little sheep!" << std::endl;
}