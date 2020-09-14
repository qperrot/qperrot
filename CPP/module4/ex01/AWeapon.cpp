/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:00:54 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/20 16:40:09 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _Name(name), _APcost(apcost), _Damage(damage)
{
	
}

AWeapon::~AWeapon()
{
	
}

AWeapon::AWeapon(AWeapon const & src) {

	*this = src;
	return ;
}

std::string const & AWeapon::getName() const {

	return this->_Name;
}

int 				AWeapon::getAPCost() const {

	return this->_APcost;
}

int 				AWeapon::getDamage() const {

	return this->_Damage;
}

AWeapon &	AWeapon::operator=(AWeapon const & rhs) {

	this->_Name = rhs.getName();
	this->_APcost = rhs.getAPCost();
	this->_Damage = rhs.getDamage();

	return *this;
}
