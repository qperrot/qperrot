/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:58:34 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/19 09:46:37 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string const name) :
	ClapTrap(name, 100, 100, 120, 120, 60, 20, 5), NinjaTrap(name) , FragTrap(name)
{

	std::cout << "Creation of the Supet Ninja named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
					
}

SuperTrap::SuperTrap() : 
	ClapTrap("DefaultSuperTrap", 100, 100, 120, 120, 60, 20, 5), NinjaTrap() , FragTrap()
{

	std::cout << "Creation of the Super Ninja named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
					
}

SuperTrap::~SuperTrap()
{
	std::cout << "Destruction of the Super Ninja named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
}

SuperTrap::SuperTrap(SuperTrap const & src) : NinjaTrap(src), FragTrap(src) {

	*this = src;
	return ;
}

SuperTrap &	SuperTrap::operator=(SuperTrap const & rhs) {

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

void	SuperTrap::rangedAttack(std::string const & target) const {

	std::cout << "FR4G-TP " << this->_Name << " attacks " << target << " with a ranged attack " << this->_Ranged_att_dam << " points de dégâts !" << std::endl;
}

void	SuperTrap::meleeAttack(std::string const & target) const {

	std::cout << "Ninja " << this->_Name << " attacks " << target << " with a melee attack " << this->_Melee_att_dam << " points de dégâts !" << std::endl;
}
