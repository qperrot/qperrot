/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:46:22 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/06 15:57:11 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int		main( void ) {

	std::string		str("HI THIS IS BRAIN");
	std::string		*point = &str;
	std::string&	ref = str;

	std::cout << "point = " << *point << std::endl;
	std::cout << "ref = " << ref << std::endl;

	
}