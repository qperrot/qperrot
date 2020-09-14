/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:00:58 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:55:06 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>
#include <iostream>
#include <iomanip> 

class AWeapon
{
	private:
		AWeapon();
		std::string		 	_Name;
		int					_APcost;
		int					_Damage;

	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & src);
		virtual ~AWeapon();
		std::string const & getName() const;
		int getAPCost() const;
		int getDamage() const;
		AWeapon &	operator=(AWeapon const & rhs);
		virtual void attack() const = 0;
};

//std::ostream &	operator<<(std::ostream & o, Victim const & rhs);
#endif