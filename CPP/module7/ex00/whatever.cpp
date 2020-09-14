/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:39:02 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/11 14:04:56 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T > 
T const &	max(T const & x, T const & y)
{
	return (x>y ? x : y);
}

template< typename T >
T const &	min(T const & x, T const & y)
{
	return (x<y ? x : y);
}

template< typename T >
void swap(T & x, T & y)
{
	T	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	float k = 42.3;
	float h = 102.54;
	::swap( k, h );
	std::cout << "k = " << k << ", h = " << h << std::endl;
	std::cout << "min( k, h ) = " << ::min( k, h ) << std::endl;
	std::cout << "max( k, h ) = " << ::max( k, h ) << std::endl;

	return 0;
}