/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:25:19 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:50:30 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <string>
#include <iostream>
#include <iomanip> 
#include <unistd.h>
#include <stdlib.h>

class Pony {

public:

	Pony ( std::string name, std::string sex, int nb_paws, std::string c_eyes, std::string c_mane, int speed );
	~Pony( void );

	void    describe( void ) const;
	void	jump( void ) const;
	void	run( void ) const;
	void	fell( void ) const;

private:

	std::string	_name;
	std::string	_sex;
	int			_nb_paws;
	std::string	_c_eyes;
	std::string	_c_mane;
	int     	_speed;
};


#endif