/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:17:09 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/20 16:43:55 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
	
}

PowerFist::PowerFist(PowerFist const & src) : AWeapon(src) {

	*this = src;
	return ;
}

void 	PowerFist::attack() const {

	std::cout << "* pschhh... SBAM ! *" << std::endl;
}

PowerFist &	PowerFist::operator=(PowerFist const & rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}
