/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:37:26 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/20 09:46:02 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include "Gryphon.hpp"
#include "Sorcerer.hpp"

int		main( void )
{
	Peon *d = new Peon("Mike");   
  	Victim *b = d; 
	Gryphon *c = new Gryphon("Harry");
  	Victim *f = c; 
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	Gryphon John("John");
	std::cout << robert << jim << joe << John;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(John);
	jim.getPolymorphed();
	John.getPolymorphed();
	c->getPolymorphed();
	delete b; 
	delete f;
	return 0;	
}