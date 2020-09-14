/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:12:48 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/05 15:24:53 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap( void )
{
	Pony*	pony2 = new Pony("Pony2", "Female", 4, "green", "red", 65);

	pony2->describe();
	pony2->run();
	pony2->jump();
	pony2->run();
	pony2->jump();
	pony2->run();
	pony2->fell();

	delete pony2;
}

void	ponyOnTheStack( void )
{
	Pony	pony1 = Pony("Pony1", "Male", 4, "blue", "brown", 50);

	pony1.describe();
	pony1.run();
	pony1.jump();
	pony1.run();
	pony1.fell();

	return ;
}

int		main( void ) {

	ponyOnTheStack();
	ponyOnTheHeap();

	std::cout << "done" << std::endl;
	return (0);
}