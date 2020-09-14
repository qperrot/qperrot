/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:53:26 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:51:15 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <iomanip> 
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

class Zombie {

public:

	Zombie ( void );
	~Zombie ( void );
	void	randomChump( void );
	void	announce( void ) const;

private:

	std::string	_name;
};


#endif