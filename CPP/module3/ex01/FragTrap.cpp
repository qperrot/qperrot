/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:02:29 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/18 15:49:05 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap(void) : 
	_Name("DefaultRobot"), 
	_Hit_point(100),
	_Max_hit(100),
	_Energy_point(100),
	_Max_energy(100),
	_Level(1),
	_Melee_att_dam(30),
	_Ranged_att_dam(20),
	_Armor_dam(5)
{

	std::cout << "Creation of the Robot named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
					
}

FragTrap::FragTrap(std::string const name) : 
	_Name(name), 
	_Hit_point(100),
	_Max_hit(100),
	_Energy_point(100),
	_Max_energy(100),
	_Level(1),
	_Melee_att_dam(30),
	_Ranged_att_dam(20),
	_Armor_dam(5)
{

	std::cout << "Creation of the Robot named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
					
}

FragTrap::~FragTrap()
{
	std::cout << "Destruction of the Robot named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) {

	*this = src;
	return ;
}

void	FragTrap::rangedAttack(std::string const & target) const {

	std::cout << "FR4G-TP " << this->_Name << " attacks " << target << " with a ranged attack " << this->_Ranged_att_dam << " points de dégâts !" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) const {

	std::cout << "FR4G-TP " << this->_Name << " attacks " << target << " with a melee attack " << this->_Melee_att_dam << " points de dégâts !" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {

	if (amount >= this->_Armor_dam)
		amount -= this->_Armor_dam;
	this->_Hit_point = (this->_Hit_point > amount) ? this->_Hit_point -= amount : 0;
	std::cout << "FR4G-TP " << this->_Name << " take damage and lost " <<  amount << " points !" << std::endl;
	
}

void	FragTrap::beRepaired(unsigned int amount) {

	this->_Hit_point = (this->_Hit_point + amount) > this->_Max_hit ? this->_Max_hit : this->_Hit_point += amount;
	this->_Energy_point = (this->_Energy_point + amount) > this->_Max_energy ? this->_Max_energy : this->_Energy_point += amount;
	std::cout << "FR4G-TP " << this->_Name << " gets " <<  amount << " life points " << "and know have " << this->_Hit_point << " life points !" << std::endl;
	std::cout << "FR4G-TP " << this->_Name << " gets " <<  amount << " Energy points " << "and know have " << this->_Energy_point << " Energy Points !" << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const & rhs) {

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

void		FragTrap::UnicornAttack(std::string const & target) {

	std::cout << this->_Name << " attacked " << target << " with a Unicorn and know " << target << " has a corn stuck in his ass well done !!" << std::endl;
	return ;
}

void		FragTrap::WarriorAttack(std::string const & target) {

	std::cout << this->_Name << " attacked " << target << " with a Saber and know " << target << " can see his heart beating well done !!" << std::endl;
	return ;
}

void		FragTrap::CrazyAttack(std::string const & target) {

	std::cout << this->_Name << " attacked " << target << " with a bazooka and blow " << target << " face off well done !!" << std::endl;
	return ;
}

void		FragTrap::DreamAttack(std::string const & target) {

	std::cout << this->_Name << " attacked " << target << " with Freddy Kruger and know " << target << " pissed in his bed well done !!" << std::endl;
	return ;
}

void		FragTrap::MomAttack(std::string const & target) {

	std::cout << this->_Name << " attacked " << target << " with " << target << " Mom, who has slapped his son in front of evryone well done Mommy !!" << std::endl;
	return ;
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target) {

	int		index;
	void	(FragTrap::* const function_array[5]) (std::string const & target) = {
		&FragTrap::UnicornAttack,
		&FragTrap::WarriorAttack,
		&FragTrap::CrazyAttack,
		&FragTrap::DreamAttack,
		&FragTrap::MomAttack,
	};
	if (this->_Energy_point < 25) {
		std::cout << "Not enought energy you are all soft Mother Fucker !" << std::endl;
		return ;
	}
	this->_Energy_point = this->_Energy_point -= 25;
	index = rand() % 5;
	(this->*function_array[index])(target);
	return ;	
}

