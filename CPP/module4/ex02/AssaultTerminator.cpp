/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:43:42 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/21 17:33:25 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src) {

	*this = src;
}

AssaultTerminator::~AssaultTerminator() {

	std::cout <<  "I’ll be back ..." << std::endl;
}

AssaultTerminator &	AssaultTerminator::operator=(AssaultTerminator const & rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}

AssaultTerminator* AssaultTerminator::clone() const {
	
	AssaultTerminator* nouveau = new AssaultTerminator(*this);

	return nouveau;
}

void AssaultTerminator::battleCry() const {

	std::cout << "This code is unclean. Purify it !" << std::endl;
}

void AssaultTerminator::rangedAttack() const {

	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const {

	std::cout <<  "* attaque with chainfists *" << std::endl;
}