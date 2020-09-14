/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:37:04 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/06 14:34:11 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int	main( void ) {

	ZombieEvent		Event;
	Zombie*			Zombie1;
	Zombie*			Zombie2;
	Zombie*			Zombie4;
	Zombie*			Zombie3;

	Zombie1 = new Zombie("Jack", "Master");
	Zombie1->advert();
	Zombie1->announce();
	delete Zombie1;

	Event.setZombieType("Killer");
	Zombie2 = Event.newZombie("Carl");
	Zombie2->advert();
	Zombie2->announce();
	delete Zombie2;

	Zombie3 = Event.randomChump();
	Zombie3->advert();
	Zombie3->announce();
	delete Zombie3;

	Event.setZombieType("Magic");
	Zombie4 = Event.randomChump();
	Zombie4->advert();
	Zombie4->announce();
	delete Zombie4;

	return (0);
}