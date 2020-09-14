/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:16:56 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/10 13:46:15 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human( void ) {

	return ;
}

Human::~Human( void ) {

	return ;
}

std::string		Human::identify( void ) const {
	
	return this->_Brain.identify();	
}

const Brain&	Human::getBrain( void ) const {

	return this->_Brain;
}