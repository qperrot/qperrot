/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:59:42 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/14 14:04:00 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed( void ) : _fixe_num(0) {

	//std::cout << "Default constructor called" << std::endl;

	return ;
}

Fixed::Fixed( Fixed const & src ) {

	//std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed::Fixed( int const num ) {

	//std::cout << "Int constructor called" << std::endl;
	this->_fixe_num = num << Fixed::_bits;
	return ;
}

Fixed::Fixed( float const num ) {

	//std::cout << "Float constructor called" << std::endl;
	this->_fixe_num = roundf(num * (1 << Fixed::_bits));
	return ;
}

Fixed::~Fixed( void ) {

	//std::cout << "Destructor called" << std::endl;

	return ;
}

float	Fixed::toFloat(void) const {

	return ((float)(this->_fixe_num) / (float)(1 << Fixed::_bits));
}

int		Fixed::toInt( void ) const {

	return this->_fixe_num >> Fixed::_bits;
}

void		Fixed::setRawBits(int const raw) {

	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixe_num = raw;

	return ;
}

int			Fixed::getRawBits(void) const {

	//std::cout << "getRawBits member function called" << std::endl;
	return ( this->_fixe_num );
}

Fixed &		Fixed::operator=( Fixed const & rhs ) {

	//std::cout << "Assignation operator called" << std::endl;

	if ( this != &rhs )
		this->_fixe_num = rhs._fixe_num;

	return *this;
}

Fixed		Fixed::operator+( Fixed const & rhs ) const {

	return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed		Fixed::operator-( Fixed const & rhs ) const {

	return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed		Fixed::operator*( Fixed const & rhs ) const {

	return Fixed( (this->toFloat() * rhs.toFloat()) );
}

Fixed		Fixed::operator/( Fixed const & rhs ) const {

	return Fixed( this->toFloat() / rhs.toFloat() );
}

bool		Fixed::operator==( Fixed const & b ) const {

	if (this->getRawBits() == b.getRawBits())
		return true;
	else
		return false;
}

bool		Fixed::operator!=( Fixed const & b ) const {

	if (this->toFloat() == b.toFloat())
		return false;
	else
		return true;
}

bool		Fixed::operator>=( Fixed const & b ) const {

	if (this->toFloat() >= b.toFloat())
		return true;
	else
		return false;
}

bool		Fixed::operator<=( Fixed const & b ) const {

	if (this->toFloat() <= b.toFloat())
		return true;
	else
		return false;
}

bool		Fixed::operator<( Fixed const & b ) const {

	if (this->toFloat() < b.toFloat())
		return true;
	else
		return false;
}

bool		Fixed::operator>( Fixed const & b ) const {

	if (this->toFloat() > b.toFloat())
		return true;
	else
		return false;
}

Fixed &			Fixed::operator++() {
	
	this->_fixe_num += 1;
	return *this ;
}

Fixed		Fixed::operator++( int ) {

	Fixed	tmp = *this;

	++*this;
	return tmp;
}

Fixed &		Fixed::operator--() {

	_fixe_num--;
	return *this;
}
Fixed		Fixed::operator--( int ) {

	Fixed	tmp = *this;

	--*this;
	return tmp;
}

Fixed const &		Fixed::min(Fixed & a, Fixed & b) {

	if (a < b)
		return a;
	else
		return b;
}

Fixed const &		Fixed::max(Fixed & a, Fixed & b) {

	if (a > b)
		return a;
	else
		return b;
}
Fixed const &		Fixed::min(Fixed const & a, Fixed const & b) {

	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

Fixed  const &		Fixed::max(Fixed const & a, Fixed const & b) {

	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

Fixed const &		min(Fixed const & a, Fixed const & b) {

	return (Fixed::min(a, b));
}
Fixed const &		max(Fixed const & a, Fixed const & b) {

	return (Fixed::max(a, b));
}
std::ostream &		operator<<(std::ostream & o, Fixed const & i) {

	o << i.toFloat();

	return o;
}