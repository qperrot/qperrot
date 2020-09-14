/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:39:11 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:53:58 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "FragTrap.hpp"

class NinjaTrap : public ClapTrap {

	private:
	
	public:
		NinjaTrap();
		NinjaTrap(std::string const name);
		NinjaTrap(NinjaTrap const & src);
		~NinjaTrap();
		NinjaTrap &	operator=(NinjaTrap const & rhs);
		void	rangedAttack(std::string const & target) const;
		void	meleeAttack(std::string const & target) const;
		void	ninjaShoebox(NinjaTrap const & rhs) const;
		void	ninjaShoebox(FragTrap const & rhs) const;
		void	ninjaShoebox(ClapTrap const & rhs) const;
		void	ninjaShoebox(ScavTrap const & rhs) const;
};

#endif