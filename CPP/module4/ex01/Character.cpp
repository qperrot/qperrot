/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:28:59 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/20 17:37:32 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string const & name ) : _Nom(name), _AP(40), _Weapon(NULL)
{
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character()
{
}

void 	Character::recoverAP() {

	this->_AP = (this->_AP >= 40) ? this->_AP : (this->_AP + 10 > 40) ? (40 - this->_AP + this->_AP) : this->_AP + 10;
}

void 	Character::equip(AWeapon* Weapon) {

	this->_Weapon = Weapon;
}

void 	Character::attack(Enemy* enemy) {

	if (this->_Weapon == NULL || this->_AP < this->_Weapon->getAPCost()) {
		std::cout << this->_Nom << " can not attaque !!!" << std::endl;
		return ;
	}
	std::cout << this->_Nom << " attaque " << enemy->getType() <<  " with a " << this->_Weapon->getName() << std::endl;
	this->_Weapon->attack();
	enemy->takeDamage(this->_Weapon->getDamage());
	this->_AP -= this->_Weapon->getAPCost();
	if (enemy->getHP() <= 0)
		delete enemy;
}

std::string const & Character::getName() const {

	return this->_Nom;
}

int 	Character::getAP() const {

	return this->_AP;
}

AWeapon 	*Character::getWeapon() const {

	return this->_Weapon;
}

Character &	Character::operator=(Character const & rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Character &rhs) {

	o << rhs.getName();
	o << " has ";
	o << rhs.getAP();
	o << " AP and ";
	if (rhs.getWeapon() == NULL)
		o << "is unarmed";
	else {
		o << "carries a ";
		o << rhs.getWeapon()->getName();
	}
	o << std::endl;

	return o;
}