/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:44:24 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:55:14 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AWeapon.hpp"

class Enemy
{
	private:
		int				_HP;
		std::string		_Type;
		Enemy();

	public:
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const &);
		virtual ~Enemy();
		std::string const & getType() const;
		int getHP() const;
		virtual void takeDamage(int);
		Enemy &	operator=(Enemy const & rhs);
};


#endif