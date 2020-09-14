/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:07:18 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/10 16:50:33 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {

	return ;
}

HumanA::~HumanA( void ) {

	return ;
}

void	HumanA::attack( void ) const {

	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
	return ;
}

void	HumanA::setWeapon(Weapon& weapon) {

	this->_weapon = weapon;
	return ;
}
