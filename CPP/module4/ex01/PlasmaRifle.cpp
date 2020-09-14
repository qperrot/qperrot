/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:16:48 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/20 16:43:49 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon(src) {

	*this = src;
	return ;
}

void 	PlasmaRifle::attack() const {

	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle &	PlasmaRifle::operator=(PlasmaRifle const & rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}