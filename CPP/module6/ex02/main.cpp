/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 09:27:05 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/11 10:23:42 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	srand(time(NULL));
	Base* one = generate();
	Base* two = generate();
	Base* three = generate();
	Base* four = generate();
	Base* five = generate();
	Base* six = generate();

	identify_from_pointer(one);
	identify_from_pointer(two);
	identify_from_pointer(three);
	identify_from_pointer(four);
	identify_from_pointer(five);
	identify_from_pointer(six);

	std::cout << std::endl;
	identify_from_reference(*one);
	identify_from_reference(*two);
	identify_from_reference(*three);
	identify_from_reference(*four);
	identify_from_reference(*five);
	identify_from_reference(*six);

	delete(one);
	delete(two);
	delete(three);
	delete(four);
	delete(five);
	delete(six);
	
	return (0);
}