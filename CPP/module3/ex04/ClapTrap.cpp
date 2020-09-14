/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:15:01 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/19 14:03:59 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name, unsigned int hit, unsigned int max_hit, unsigned int energy, unsigned int max_energy, unsigned int melee, unsigned int ranged, unsigned int armor) :
	_Name(name), 
	_Hit_point(hit),
	_Max_hit(max_hit),
	_Energy_point(energy),
	_Max_energy(max_energy),
	_Level(1),
	_Melee_att_dam(melee),
	_Ranged_att_dam(ranged),
	_Armor_dam(armor)
{
	std::cout << "Creation of ClapTrap " << this->_Name << " level " << this->_Level << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destruction of ClapTrap " << this->_Name << " level " << this->_Level << std::endl;
	return ;
}

ClapTrap::ClapTrap( void ) :
	_Name("DefaultClap"), 
	_Hit_point(100),
	_Max_hit(100),
	_Energy_point(70),
	_Max_energy(70),
	_Level(1),
	_Melee_att_dam(25),
	_Ranged_att_dam(10),
	_Armor_dam(2)
{
	std::cout << "Creation of ClapTrap " << this->_Name << " level " << this->_Level << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_Name(name), 
	_Hit_point(100),
	_Max_hit(100),
	_Energy_point(70),
	_Max_energy(70),
	_Level(1),
	_Melee_att_dam(25),
	_Ranged_att_dam(10),
	_Armor_dam(2)
{
	std::cout << "Creation of ClapTrap " << this->_Name << " level " << this->_Level << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {

	*this = src;
	return ;
}

// void	ClapTrap::rangedAttack(std::string const & target) const {

// 	std::cout << "FR4G-TP " << this->_Name << " attacks " << target << " with a ranged attack " << this->_Ranged_att_dam << " points de dégâts !" << std::endl;
// }

// void	ClapTrap::meleeAttack(std::string const & target) const {

// 	std::cout << "FR4G-TP " << this->_Name << " attacks " << target << " with a melee attack " << this->_Melee_att_dam << " points de dégâts !" << std::endl;
// }

void	ClapTrap::takeDamage(unsigned int amount) {

	if (amount >= this->_Armor_dam)
		amount -= this->_Armor_dam;
	this->_Hit_point = (this->_Hit_point > amount) ? this->_Hit_point -= amount : 0;
	std::cout << "FR4G-TP " << this->_Name << " take damage and lost " <<  amount << " points !" << std::endl;
	
}

void	ClapTrap::beRepaired(unsigned int amount) {

	this->_Hit_point = (this->_Hit_point + amount) > this->_Max_hit ? this->_Max_hit : this->_Hit_point += amount;
	this->_Energy_point = (this->_Energy_point + amount) > this->_Max_energy ? this->_Max_energy : this->_Energy_point += amount;
	std::cout << "FR4G-TP " << this->_Name << " gets " <<  amount << " life points " << "and know have " << this->_Hit_point << " life points !" << std::endl;
	std::cout << "FR4G-TP " << this->_Name << " gets " <<  amount << " Energy points " << "and know have " << this->_Energy_point << " Energy Points !" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs) {

	this->_Hit_point = rhs._Hit_point;
	this->_Max_hit = rhs._Max_hit;
	this->_Energy_point = rhs._Energy_point;
	this->_Max_energy = rhs._Max_energy;
	this->_Armor_dam = rhs._Armor_dam;
	this->_Melee_att_dam = rhs._Melee_att_dam;
	this->_Ranged_att_dam = rhs._Ranged_att_dam;
	this->_Level = rhs._Level;
	this->_Name = rhs._Name;
	return *this;
}

std::string		ClapTrap::getName( void ) const {

	return this->_Name;
}