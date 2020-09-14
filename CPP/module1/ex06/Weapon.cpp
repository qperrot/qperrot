/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:07:25 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/10 15:53:00 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( const std::string type) : _type(type) {

	return ;
}

Weapon::~Weapon( void ) {

	return ;
}

const std::string&	Weapon::getType( void ) const {

	return this->_type;
}

void	Weapon::setType(const std::string set_type) {

	this->_type = set_type;
	return ;
}