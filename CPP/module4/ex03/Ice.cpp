/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:10:18 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/25 17:15:58 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {

	return ;
}

Ice::Ice(std::string const & type) : AMateria(type) {

	return ;
}

Ice::Ice(Ice const & rhs) : AMateria(rhs) {

	*this = rhs;
}

Ice::~Ice() {

}

Ice &	Ice::operator=(Ice const & rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}

AMateria* Ice::clone() const {

	AMateria* nouveau = new Ice(*this);
	return nouveau;
}

void	Ice::use(ICharacter& target) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}