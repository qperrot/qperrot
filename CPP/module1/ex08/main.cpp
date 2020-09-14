/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:48:12 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/12 09:09:20 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main( void ) {

	Human	human1;

	human1.action("meleeAttack", "Jack");
	human1.action("rangedAttack", "Mike");
	human1.action("intimidatingShout", "Jane");
	human1.action("Shoot", "Jane");
	return (0);
}