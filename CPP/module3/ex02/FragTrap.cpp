/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:13:39 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/19 09:27:28 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const name) : 
	ClapTrap("DefaultRobot", 100, 100, 30, 20, 5)
{

	std::cout << "Creation of the Robot named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
					
}

FragTrap::FragTrap(std::string const name) : 
	ClapTrap(name, 100, 100, 30, 20, 5)
{

	std::cout << "Creation of the Robot named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
					
}

FragTrap::~FragTrap()
{
	std::cout << "Destruction of the Robot named " << this->_Name << " level " << this->_Level << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {

	*this = src;
	return ;
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

void	FragTrap::rangedAttack(std::string const & target) const {

	std::cout << "FR4G-TP " << this->_Name << " attacks " << target << " with a ranged attack " << this->_Ranged_att_dam << " points de dégâts !" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) const {

	std::cout << "FR4G-TP " << this->_Name << " attacks " << target << " with a melee attack " << this->_Melee_att_dam << " points de dégâts !" << std::endl;
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

