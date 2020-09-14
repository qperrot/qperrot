/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:37:15 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:53:08 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const; 
		
	private:
		int					_fixe_num;
		static const int	_bits;
};

std::ostream &		operator<<(std::ostream & o, Fixed const & i);
Fixed const &		min( Fixed const & a, Fixed const & b );
Fixed const &		max( Fixed const & a, Fixed const & b );

#endif