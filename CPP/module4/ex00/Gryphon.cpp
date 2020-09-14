/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gryphon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:29:27 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/19 17:52:50 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gryphon.hpp"

Gryphon::Gryphon(std::string name) : Victim(name)
{
	std::cout << "Gry Gry." << std::endl;
}

Gryphon::Gryphon(Gryphon const & src) : Victim(src)
{
	*this = src;
	std::cout << "Gry Gry." << std::endl;
	return ;
}

Gryphon::~Gryphon()
{
	std::cout << "Grrr..." << std::endl;
}

std::string		Gryphon::getName( void ) const {

	return (this->_Nom);
}

// std::ostream &	operator<<(std::ostream & o, Gryphon const & rhs) {

// 	o << "I 'm ";
// 	o << rhs.getName();
// 	o << " and I like otters!";
// 	o << std::endl;
// 	return o;
// }

Gryphon &	Gryphon::operator=(Gryphon const & rhs) {

	this->_Nom = rhs.getName();
	return *this;
}

void		Gryphon::getPolymorphed() const {

	std::cout << this->getName() << " has been turned into a strange otter!" << std::endl;
}