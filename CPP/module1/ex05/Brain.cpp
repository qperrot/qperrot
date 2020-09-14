/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:17:00 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/10 10:51:15 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {

	return ;
}

Brain::~Brain( void ) {
	
	return ;
}

std::string		Brain::identify( void ) const {

	const void * address = static_cast<const void*>(this);
	std::stringstream ss;
	ss << address;  
	std::string str_a = ss.str(); 
	return str_a;
}