/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:37:35 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/19 17:31:37 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer(std::string name, std::string titre) : _Nom(name), _Titre(titre)
{
	std::cout << this->_Nom << ", " << this->_Titre << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
	std::cout << this->_Nom << ", " << this->_Titre << ", is born!" << std::endl;
	return ;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->_Nom << ", " << this->_Titre << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string		Sorcerer::getName( void ) const {

	return (this->_Nom);
}

std::string		Sorcerer::getTitre( void ) const {

	return (this->_Titre);
}

std::ostream &	operator<<(std::ostream & o, Sorcerer const & rhs) {

	o << "I am ";
	o << rhs.getName();
	o << ", ";
	o << rhs.getTitre();
	o << ", and i like ponies!";
	o << std::endl;
	return o;
}

Sorcerer &	Sorcerer::operator=(Sorcerer const & rhs) {

	this->_Nom = rhs.getName();
	this->_Titre = rhs.getTitre();

	return *this;
}

void 			Sorcerer::polymorph(Victim const &rhs) const {

	rhs.getPolymorphed();
	return ;
}