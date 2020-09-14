/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:10:28 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/25 17:16:07 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {

	return ;
}

Cure::Cure(std::string const & type) : AMateria(type) {

	return ;
}

Cure::Cure(Cure const & rhs) : AMateria(rhs) {

	*this = rhs;
}

Cure::~Cure() {

}

Cure &	Cure::operator=(Cure const & rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}

AMateria* Cure::clone() const {

	AMateria* nouveau = new Cure(*this);
	return nouveau;
}

void	Cure::use(ICharacter& target) {

	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	AMateria::use(target);
}