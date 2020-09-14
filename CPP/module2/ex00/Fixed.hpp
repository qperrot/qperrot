/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:48:15 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:52:56 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>


class Fixed {
	public:
		Fixed( void );
		Fixed( Fixed const & src );
		~Fixed ( void );

		Fixed &		operator=( Fixed const & rhs );
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
	private:
		int					_fixe_num;
		static const int	_bits;
};

#endif