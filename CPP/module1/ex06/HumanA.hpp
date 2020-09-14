/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:07:10 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:52:07 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

public:

	HumanA ( std::string name, Weapon& weapon );
	~HumanA ( void );
	void	attack( void ) const;
	void	setWeapon(Weapon& weapon);


private:

	std::string		_name;
	Weapon&			_weapon;
};


#endif