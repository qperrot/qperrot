/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:28:47 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:55:10 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Enemy.hpp"

class Character
{
	private:
		std::string		_Nom;
		int				_AP;
		AWeapon			*_Weapon;
		Character();

	public:
		Character(std::string const & name);
		Character(Character const &);
		virtual ~Character();
		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
		std::string const & getName() const;
		int	getAP() const;
		AWeapon 	*getWeapon() const;
		//virtual void takeDamage(int);
		Character &	operator=(Character const & rhs);
};

std::ostream &	operator<<(std::ostream & o, Character &rhs);


#endif