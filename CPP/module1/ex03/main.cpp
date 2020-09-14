/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:37:04 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/06 15:43:59 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

void	split_horde( void ) {

	std::cout << std::endl;
	std::cout << ".................NEW HORDE.................." << std::endl;
	std::cout << std::endl;
}

int	main( void ) {

	split_horde();
	ZombieHorde		Horde1(4);
	split_horde();
	ZombieHorde		Horde2(2);
	split_horde();
	ZombieHorde		Horde3(10);
	split_horde();
	ZombieHorde		Horde4(15);

	return (0);
}