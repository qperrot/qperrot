/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:42:49 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/06 15:35:09 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int n ) {

	if (n > 0)
		this->_n = n;
	else
		this->_n = 1;

	std::cout << "Horde begin" << std::endl;
	this->_Zombie = new Zombie[this->_n];
	for (int i=0; i < n; i++) {
		this->_Zombie[i].randomChump();
		this->_Zombie[i].announce();
	}
	return ;
}

ZombieHorde::~ZombieHorde( void ) {

	delete [] this->_Zombie;
	std::cout << "Horde end" << std::endl;
	return ;
}

void	Zombie::randomChump( void ) {

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
	this->_name = name;
}

void	Zombie::announce( void ) const {

	std::cout << "new Zombie name is " << this->_name << std::endl;
}
