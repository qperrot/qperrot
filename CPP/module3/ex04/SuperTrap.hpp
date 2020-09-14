/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:58:48 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:54:18 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap {
	
	public:
		SuperTrap();
		SuperTrap(std::string const name);
		SuperTrap(SuperTrap const & src);
		~SuperTrap();
		SuperTrap &	operator=(SuperTrap const & rhs);
		void	rangedAttack(std::string const & target) const;
		void	meleeAttack(std::string const & target) const;
};

#endif