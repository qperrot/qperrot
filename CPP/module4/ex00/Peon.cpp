/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:45:35 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/19 17:52:56 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & src) : Victim(src)
{
	*this = src;
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

std::string		Peon::getName( void ) const {

	return (this->_Nom);
}

// std::ostream &	operator<<(std::ostream & o, Peon const & rhs) {

// 	o << "I 'm ";
// 	o << rhs.getName();
// 	o << " and I like otters!";
// 	o << std::endl;
// 	return o;
// }

Peon &	Peon::operator=(Peon const & rhs) {

	this->_Nom = rhs.getName();
	return *this;
}

void		Peon::getPolymorphed() const {

	std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}