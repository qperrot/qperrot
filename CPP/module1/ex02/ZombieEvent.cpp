/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:54:03 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/06 14:40:17 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void ) : _type("Amateur") {

	std::cout << "Event begin" << std::endl;
	return ;
}

ZombieEvent::~ZombieEvent( void ) {

	std::cout << "Event end" << std::endl;
	return ;
}

void	ZombieEvent::setZombieType( std::string type ) {

	this->_type = type;
	return ;
}

Zombie	*	ZombieEvent::newZombie(std::string name) {

	return new Zombie(name, this->_type);
}

void	Zombie::announce( void ) const {

	std::cout << "new Zombie name is " << this->_name << " and type is " << this->_type << std::endl;
}

Zombie*	ZombieEvent::randomChump() {

	Zombie			*zombie;
	std::string		name= "";
	char			chara;

	for (int i=0; i < 7; i++) {
		if (i == 0) {
			chara = (rand() % 26) + 65;
			name += chara;
		}
		else {
			chara = (rand() % 26) + 97;
			name += chara;
		}
	}
	zombie = newZombie(name);
	return (zombie);
}
