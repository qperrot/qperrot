/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:48:01 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/14 10:44:37 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed( void ) : _fixe_num(0) {

	std::cout << "Default constructor called" << std::endl;

	return ;
}

Fixed::Fixed( Fixed const & src ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed::Fixed( int const num ) {

	std::cout << "Int constructor called" << std::endl;
	this->_fixe_num = (num << Fixed::_bits);
	return ;
}

Fixed::Fixed ( float const num ) {

	std::cout << "Float constructor called" << std::endl;
	this->_fixe_num = roundf(num * (1 << Fixed::_bits));
	return ;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;

	return ;
}

float	Fixed::toFloat(void) const {

	return ((float)(this->_fixe_num) / (float)(1 << Fixed::_bits));
}

int		Fixed::toInt( void ) const {

	return this->_fixe_num >> Fixed::_bits;
}

void		Fixed::setRawBits(int const raw) {

	std::cout << "setRawBits member function called" << std::endl;
	this->_fixe_num = raw;

	return ;
}

int			Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return ( this->_fixe_num );
}

Fixed &		Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Assignation operator called" << std::endl;

	if ( this != &rhs )
		this->_fixe_num = rhs.getRawBits();

	return *this;
}

std::ostream &		operator<<(std::ostream & o, Fixed const & i) {

	o << i.toFloat();

	return o;
}