/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:13:59 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/18 15:54:01 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

int		main( void )
{
	FragTrap	Jack("Jack");
	FragTrap	Carl("Carl");
	ScavTrap	Marc("Marc");
	ScavTrap	Xav("Xav");
	NinjaTrap	Jean("Jean");
	NinjaTrap	Kyle;
	ClapTrap	Lili;

	Kyle = Jean;
	Jack.rangedAttack("Carl");
	Carl.takeDamage(20);
	Jack.meleeAttack("Carl");
	Carl.takeDamage(30);
	Carl.beRepaired(50);
	Jack.vaulthunter_dot_exe("Carl");
	Carl.takeDamage(20);
	Carl.vaulthunter_dot_exe("Jack");
	Jack.takeDamage(20);
	Carl.vaulthunter_dot_exe("Jack");
	Jack.takeDamage(20);
	Carl.vaulthunter_dot_exe("Jack");
	Jack.takeDamage(20);
	Carl.vaulthunter_dot_exe("Jack");
	Jack.takeDamage(20);
	Carl.vaulthunter_dot_exe("Jack");

	Marc.rangedAttack("Carl");
	Xav.takeDamage(15);
	Marc.meleeAttack("Xav");
	Xav.takeDamage(20);
	Xav.beRepaired(10);
	Marc.challengeNewcomer("Xav");
	Xav.takeDamage(20);
	Xav.challengeNewcomer("Marc");
	Marc.takeDamage(20);
	Xav.challengeNewcomer("Marc");
	Marc.takeDamage(20);
	Xav.challengeNewcomer("Marc");
	Marc.takeDamage(20);
	Xav.challengeNewcomer("Marc");
	Marc.takeDamage(20);
	Xav.challengeNewcomer("Marc");

	Jean.rangedAttack("Carl");
	Kyle.takeDamage(15);
	Jean.meleeAttack("Kyle");
	Kyle.takeDamage(20);
	Kyle.beRepaired(10);
	Jean.ninjaShoebox(Kyle);
	Kyle.takeDamage(20);
	Kyle.ninjaShoebox(Jean);
	Jean.takeDamage(20);
	Kyle.ninjaShoebox(Jack);
	Jean.takeDamage(20);
	Kyle.ninjaShoebox(Lili);
	Jean.takeDamage(20);
	Kyle.ninjaShoebox(Xav);
	Jean.takeDamage(20);
	Kyle.ninjaShoebox(Marc);
	return (0);
}