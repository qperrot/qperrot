/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:25:06 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/05 16:29:14 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony( std::string name, std::string sex, int nb_paws, std::string c_eyes, std::string c_mane, int speed ) : _name(name), _sex(sex), _nb_paws(nb_paws), _c_eyes(c_eyes), _c_mane(c_mane), _speed(speed) {

	std::cout << this->_name << " is born" << std::endl;
	return ;
}

Pony::~Pony( void ) {

	std::cout << this->_name << " died" << std::endl;
	return ;
}

void	Pony::describe( void ) const {

	std::cout << this->_name << " it is a " << this->_sex << " with " << this->_nb_paws << " paws and " << this->_c_eyes << " eyes and " << this->_c_mane << " mane." << std::endl;
	
}

void	Pony::run( void ) const {
	
	std::cout << this->_name << " is running at a speed of " << this->_speed << " km/h." << std::endl;
}

void	Pony::jump( void ) const {

	std::cout << this->_name << " is jumping over the bar." << std::endl;
}

void	Pony::fell( void ) const {

	std::cout << this->_name << " just broke is leg and falls." << std::endl;
}
