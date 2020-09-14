/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 14:57:38 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/09 10:39:23 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"	

int 	main(int argc, char** argv)
{
	std::string			num;

	if (argc != 2) {
		std::cout << "ERROR: Wrong number of arg !!" << std::endl;
		return 0;
	}
	num = argv[1];
	try 
	{
		Convert		Conv(argv[1]);
		Conv.PrintChar();
		Conv.PrintInt();
		Conv.PrintFloat();
		Conv.PrintDouble();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	catch (int i) {}
	return 0;
}