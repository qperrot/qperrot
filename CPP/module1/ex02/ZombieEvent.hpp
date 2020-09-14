/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:54:19 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:50:48 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent {

public:

	ZombieEvent ( void );
	~ZombieEvent ( void );
	void	setZombieType( std::string type );
	Zombie* newZombie (std::string name);
	Zombie*	randomChump(void);

private:

	std::string	_type;
};


#endif