/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:14:08 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/19 14:28:28 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

ScavTrap::ScavTrap(void) : 
	ClapTrap("DefaultMysterio", 100, 100, 50, 50, 20, 15, 3)
{
	srand(time(NULL));
	std::cout << "Creation of Mysterio named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
					
}

ScavTrap::ScavTrap(std::string const name) : 
	ClapTrap(name, 100, 100, 50, 50, 20, 15, 3)
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

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src){

	srand(time(NULL));
	*this = src;
	return ;
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

void	ScavTrap::rangedAttack(std::string const & target) const {

	std::cout << "Mysterio " << this->_Name << " attacks " << target << " with a Mysterio ranged attack " << this->_Ranged_att_dam << " points de dégâts !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target) const {

	std::cout << "Mysterio " << this->_Name << " attacks " << target << " with a Mysterio melee attack " << this->_Melee_att_dam << " points de dégâts !" << std::endl;
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

std::string		ScavTrap::getName( void ) const {

	return this->_Name;
}