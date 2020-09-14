/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 14:00:21 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/14 14:03:22 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(a);
	Fixed d(Fixed(7.6254f) / Fixed(0.7f));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	std::cout << "a = " << a << "b = " << b << std::endl;
	std::cout << "Max = ";
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << "Min = ";
	std::cout << Fixed::min(a, b) << std::endl;

	std::cout << "c = " << c << "d = " << d << std::endl;
	std::cout << "Max = ";
	std::cout << Fixed::max(c, d) << std::endl;
	std::cout << "Min = ";
	std::cout << Fixed::min(c, d) << std::endl;

	std::cout << "b = " << b << "c = " << c << std::endl;
	std::cout << "Max = ";
	std::cout << Fixed::max(b, c) << std::endl;
	std::cout << "Min = ";
	std::cout << Fixed::min(b, c) << std::endl;


	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = ";
	std::cout << a-- << std::endl;
	std::cout << "a * b = ";
	std::cout << (a * b) << std::endl;
	std::cout << "a / b = ";
	std::cout << (a / b) << std::endl;
	std::cout << "a + c = ";
	std::cout << (a + c) << std::endl;

	std::cout << "d = " << d << std::endl;
	std::cout << "--d = ";
	std::cout << --d << std::endl;
	std::cout << "d / c = ";
	std::cout << (d / c) << std::endl;
	std::cout << "d * b = ";
	std::cout << (d * b) << std::endl;
	std::cout << "d - a = ";
	std::cout << (d - a) << std::endl;

	std::cout << "c = " << c << "d = " << d << std::endl;
	std::cout << "Max = ";
	std::cout << max(c, d) << std::endl;
	std::cout << "Min = ";
	std::cout << min(c, d) << std::endl;

	std::cout << "      COMPARE     " << std::endl;
	std::cout << "c = " << c << "d = " << d << std::endl;
	std::cout << "c <= d is ";
	if (c <= d)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	std::cout << "a = " << a << "b = " << b << std::endl;
	std::cout << "a >= b is ";
	if (a >= b)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	std::cout << "c = " << c << "b = " << b << std::endl;
	std::cout << "c == b is ";
	if (c == b)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	std::cout << "d = " << d << "a = " << a << std::endl;
	std::cout << "d < a is ";
	if (d < a)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	return 0;
}