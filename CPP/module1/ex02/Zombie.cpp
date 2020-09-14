/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:53:41 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/06 14:36:53 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {

	std::cout << "Zombie born" << std::endl;
	return ;
}

Zombie::~Zombie( void ) {
	
	std::cout << "Zombie died" << std::endl;
}

void    Zombie::advert( void ) const {
	
	std::cout << "< " << this->_name << " > " << "( " << this->_type << " )" << " Braiiiiiiinnnnsss....." << std::endl;
}
