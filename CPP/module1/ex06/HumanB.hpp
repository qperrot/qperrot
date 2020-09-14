/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:07:06 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:52:06 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

public:

	HumanB ( std::string name );
	~HumanB ( void );
	void	attack( void ) const;
	void	setWeapon(Weapon& weapon );


private:

	std::string		_name;
	Weapon		 	*_weapon;
};


#endif