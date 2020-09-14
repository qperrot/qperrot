/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 09:13:49 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:53:44 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
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
		void		vaulthunter_dot_exe(std::string const & target);
		void		rangedAttack(std::string const & target) const;
		void		meleeAttack(std::string const & target) const;
};

class ScavTrap : public ClapTrap
{	
	public:
		ScavTrap( void );
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();
		ScavTrap &	operator=(ScavTrap const & rhs);
		void		challengeNewcomer(std::string const & target);
		void		rangedAttack(std::string const & target) const;
		void		meleeAttack(std::string const & target) const;
};




#endif