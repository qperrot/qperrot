/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:57:54 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/20 17:56:25 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Break everything !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & src) : Enemy(src)
{
    std::cout << "Gaaah. Break everything !" << std::endl;
	*this = src;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh ..." << std::endl;
}

void 	SuperMutant::takeDamage(int amount) {

	amount -= 3;
    Enemy::takeDamage(amount);
}


SuperMutant &	SuperMutant::operator=(SuperMutant const & rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}