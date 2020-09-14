/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:13:49 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:54:09 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

	private:
		void		UnicornAttack(std::string const & target);
		void		WarriorAttack(std::string const & target);
		void		CrazyAttack(std::string const & target);
		void		DreamAttack(std::string const & target);
		void		MomAttack(std::string const & target);

	public:
		FragTrap(std::string const name);
		FragTrap( void );
		FragTrap(std::string const name, unsigned int hit, unsigned int max_hit, unsigned int energy, unsigned int max_energy, unsigned int melee, unsigned int ranged, unsigned int armor);
		FragTrap(FragTrap const & src);
		~FragTrap();
		FragTrap &	operator=(FragTrap const & rhs);
		void		vaulthunter_dot_exe(std::string const & target);
		std::string	getName( void ) const;
		void		rangedAttack(std::string const & target) const;
		void		meleeAttack(std::string const & target) const;
};

class ScavTrap : public ClapTrap {

	public:
		ScavTrap( void );
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();
		ScavTrap &	operator=(ScavTrap const & rhs);
		void		challengeNewcomer(std::string const & target);
		std::string	getName( void ) const;
		void		rangedAttack(std::string const & target) const;
		void		meleeAttack(std::string const & target) const;
};




#endif