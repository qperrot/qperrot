/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:42:48 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/17 13:57:45 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int		main( void )
{
	FragTrap	Jack("Jack");
	FragTrap	Carl("Carl");

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
	return (0);
}