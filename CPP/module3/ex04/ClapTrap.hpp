/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:14:41 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:54:05 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h> 

class ClapTrap
{
	protected:
		std::string		_Name;
		unsigned int	_Hit_point;
		unsigned int	_Max_hit;
		unsigned int	_Energy_point;
		unsigned int	_Max_energy;
		unsigned int	_Level;
		unsigned int	_Melee_att_dam;
		unsigned int	_Ranged_att_dam;
		unsigned int	_Armor_dam;

	public:
		ClapTrap( void );
		ClapTrap(std::string name, unsigned int hit, unsigned int max_hit, unsigned int energy, unsigned int max_energy, unsigned int melee, unsigned int ranged, unsigned int armor);
		ClapTrap(ClapTrap const & src);
		ClapTrap(std::string name);
		virtual~ClapTrap();
		ClapTrap &	operator=(ClapTrap const & rhs);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName( void ) const;
};



#endif