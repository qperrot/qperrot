/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:59:25 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:53:03 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

//const int	Fixed::_bits = 8;

class Fixed {
	public:
		Fixed( void );
		Fixed( int const num );
		Fixed ( float const num );
		Fixed( Fixed const & src );
		~Fixed ( void );

		Fixed &		operator=( Fixed const & rhs );
		Fixed		operator+( Fixed const & rhs ) const;
		Fixed		operator-( Fixed const & rhs ) const;
		Fixed		operator*( Fixed const & rhs ) const;
		Fixed		operator/( Fixed const & rhs ) const;

		bool		operator==( Fixed const & b ) const;
		bool		operator!=( Fixed const & b ) const;
		bool		operator<=( Fixed const & b ) const;
		bool		operator>=( Fixed const & b ) const;
		bool		operator<( Fixed const & b ) const;
		bool		operator>( Fixed const & b ) const;

		Fixed &		operator++();
		Fixed		operator++( int );
		Fixed &		operator--();
		Fixed		operator--( int );

		static Fixed const &		min( Fixed & a, Fixed & b );
		static Fixed const &		max( Fixed & a, Fixed & b );
		static Fixed const &		min( Fixed const & a, Fixed const & b );
		static Fixed const &		max( Fixed const & a, Fixed const & b );
		//static Fixed &		min( Fixed & const a, Fixed & b );
		//static Fixed &		max( Fixed & const a, Fixed & b );
		// static Fixed const &		min( Fixed & a, Fixed & const b );
		// static Fixed const &		max( Fixed & a, Fixed & const b );
		//static Fixed &		min( Fixed & const a, Fixed & const b );
		//static Fixed &		max( Fixed & const a, Fixed & const b );

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const; 
		
	private:
		int					_fixe_num;
		static const int	_bits;
};
// const int	Fixed::_bits = 8;
std::ostream &		operator<<(std::ostream & o, Fixed const & i);
Fixed const &		min( Fixed const & a, Fixed const & b );
Fixed const &		max( Fixed const & a, Fixed const & b );
// Fixed &		min( Fixed & a, Fixed & b );
// Fixed &		max( Fixed & a, Fixed & b );

//bool		operator==(Fixed const & a, Fixed const & b) const;

#endif