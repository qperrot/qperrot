/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:04:20 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/19 14:28:56 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

ScavTrap::ScavTrap( void ) : 
	_Name("DefaultMysterio"), 
	_Hit_point(100),
	_Max_hit(100),
	_Energy_point(50),
	_Max_energy(50),
	_Level(1),
	_Melee_att_dam(20),
	_Ranged_att_dam(15),
	_Armor_dam(3)
{

	srand(time(NULL));
	std::cout << "Creation of Mysterio named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
					
}

ScavTrap::ScavTrap(std::string const name) : 
	_Name(name), 
	_Hit_point(100),
	_Max_hit(100),
	_Energy_point(50),
	_Max_energy(50),
	_Level(1),
	_Melee_att_dam(20),
	_Ranged_att_dam(15),
	_Armor_dam(3)
{

	srand(time(NULL));
	std::cout << "Creation of Mysterio named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
					
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destruction of Mysterio named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) {

	srand(time(NULL));
	*this = src;
	return ;
}

void	ScavTrap::rangedAttack(std::string const & target) const {

	std::cout << "Mysterio " << this->_Name << " attacks " << target << " with a Mysterio ranged attack " << this->_Ranged_att_dam << " points de dégâts !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target) const {

	std::cout << "Mysterio " << this->_Name << " attacks " << target << " with a Mysterio melee attack " << this->_Melee_att_dam << " points de dégâts !" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {

	if (amount >= this->_Armor_dam)
		amount -= this->_Armor_dam;
	this->_Hit_point = (this->_Hit_point > amount) ? this->_Hit_point -= amount : 0;
	std::cout << "Mysterio " << this->_Name << " take damage and lost " <<  amount << " points but keeps watching the door!" << std::endl;
	
}

void	ScavTrap::beRepaired(unsigned int amount) {

	this->_Hit_point = (this->_Hit_point + amount) > this->_Max_hit ? this->_Max_hit : this->_Hit_point += amount;
	this->_Energy_point = (this->_Energy_point + amount) > this->_Max_energy ? this->_Max_energy : this->_Energy_point += amount;
	std::cout << "Mysterio " << this->_Name << " gets " <<  amount << " life points " << "and know have " << this->_Hit_point << " life points  but keeps watching the door !" << std::endl;
	std::cout << "Mysterio " << this->_Name << " gets " <<  amount << " Energy points " << "and know have " << this->_Energy_point << " Energy Points but keeps watching the door !" << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs) {

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

void		ScavTrap::challengeNewcomer(std::string const & target) {

	std::string	challenge_set[4] = {"I challenge you to drive as fast you can into a wall",
									"I challenge you to swimme into lava",
									"I challenge you to drink soupe with a fork and eat meat with a baby spoon in less than 2 min",
									"I challenge you to creat a challenge and to do it on October 32"};
	if (this->_Energy_point < 25) {
		std::cout << "Not enought energy you are all soft Mother Fucker !" << std::endl;
		return ;
	}
	this->_Energy_point = this->_Energy_point -= 25;
	std::cout << "Hey " << target << " " << this->_Name << " has a challenge for you :" << std::endl; 
	std::cout << challenge_set[rand() % 4] << std::endl;
	return ;	
}