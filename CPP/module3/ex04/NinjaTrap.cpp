/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:38:56 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/19 14:20:24 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string const name) : 
	ClapTrap(name, 60, 60, 120, 120, 60, 5, 0)
{
	srand(time(NULL));

	std::cout << "Creation of the Ninja named " << this->_Name << " level " << this->_Level << std::endl;
	return ;					
}

NinjaTrap::NinjaTrap() : 
	ClapTrap("DefaultNinja", 60, 60, 120, 120, 60, 5, 0)
{
	srand(time(NULL));
	std::cout << "Creation of the Ninja named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
					
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "Destruction of the Ninja named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src) {

	srand(time(NULL));
	*this = src;
	return ;
}

NinjaTrap &	NinjaTrap::operator=(NinjaTrap const & rhs) {

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

void	NinjaTrap::rangedAttack(std::string const & target) const {

	std::cout << "Ninja " << this->_Name << " attacks " << target << " with a ranged attack " << this->_Ranged_att_dam << " points de dégâts !" << std::endl;
}

void	NinjaTrap::meleeAttack(std::string const & target) const {

	std::cout << "Ninja " << this->_Name << " attacks " << target << " with a melee attack " << this->_Melee_att_dam << " points de dégâts !" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const & rhs) const {

	std::cout << "Ninja named " << this->_Name << " attack the Ninja named " << rhs._Name << ". They are fighting hard but " << this->_Name << " is stronger and put his Katana...Oh good not here NOT HERE....." << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap const & rhs) const {

	std::cout << "Ninja named " << this->_Name << " attack the robot named " << rhs.getName() << " and know " << rhs.getName() << " is nothing more than a mixer poooooor robot !!!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap const & rhs) const {

	std::cout << "Ninja named " << this->_Name << " attack the robot named " << rhs.getName() << " and know " << rhs.getName() << " is nothing more than a mixer poooooor robot !!!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const & rhs) const {

	std::cout << "Ninja named " << this->_Name << " attack the Mysterio named " << rhs.getName() << " no more game just collateral damages, " << rhs.getName() << " is on the floor and the Ninja can come inside ready to kill !!!" << std::endl;
}

