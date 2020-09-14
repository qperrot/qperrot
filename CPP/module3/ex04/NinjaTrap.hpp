/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:39:11 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:54:13 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "FragTrap.hpp"

class NinjaTrap : public virtual ClapTrap {

	public:
		NinjaTrap();
		NinjaTrap(std::string const name, unsigned int hit, unsigned int max_hit, unsigned int energy, unsigned int max_energy, unsigned int melee, unsigned int ranged, unsigned int armor);
		NinjaTrap(std::string const name);
		NinjaTrap(NinjaTrap const & src);
		~NinjaTrap();
		NinjaTrap &	operator=(NinjaTrap const & rhs);
		void	ninjaShoebox(NinjaTrap const & rhs) const;
		void	ninjaShoebox(FragTrap const & rhs) const;
		void	ninjaShoebox(ClapTrap const & rhs) const;
		void	ninjaShoebox(ScavTrap const & rhs) const;
		void	rangedAttack(std::string const & target) const;
		void	meleeAttack(std::string const & target) const;
};

#endif