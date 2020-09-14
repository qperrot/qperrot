/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:42:45 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:53:23 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h> 

class FragTrap
{
	private:
		std::string		_Name;
		unsigned int	_Hit_point;
		unsigned int	_Max_hit;
		unsigned int	_Energy_point;
		unsigned int	_Max_energy;
		unsigned int	_Level;
		unsigned int	_Melee_att_dam;
		unsigned int	_Ranged_att_dam;
		unsigned int	_Armor_dam;

		void		UnicornAttack(std::string const & target);
		void		WarriorAttack(std::string const & target);
		void		CrazyAttack(std::string const & target);
		void		DreamAttack(std::string const & target);
		void		MomAttack(std::string const & target);

	
	public:
		FragTrap( void );
		FragTrap(std::string const name);
		FragTrap(FragTrap const & src);
		~FragTrap();
		FragTrap &	operator=(FragTrap const & rhs);
		void		rangedAttack(std::string const & target) const;
		void		meleeAttack(std::string const & target) const;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		vaulthunter_dot_exe(std::string const & target);
};




#endif