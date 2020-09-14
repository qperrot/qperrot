/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:53:41 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/06 15:29:23 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {

	std::cout << "Zombie born" << std::endl;
	return ;
}

Zombie::~Zombie( void ) {
	
	std::cout << "Zombie died" << std::endl;
}
