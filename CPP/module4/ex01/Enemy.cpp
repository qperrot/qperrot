/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:44:13 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/20 17:52:42 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type) : _HP(hp), _Type(type)
{
	
}

Enemy::Enemy(Enemy const & src) {

	*this = src ;
}

Enemy::~Enemy()
{
}

std::string const & Enemy::getType() const {

	return this->_Type;
}

int Enemy::getHP() const {

	return this->_HP;
}
void 	Enemy::takeDamage(int amount) {

	if (this->_HP > amount)
		this->_HP -= amount;
	else if (this->_HP <= amount && this->_HP > 0)
		this->_HP = 0;
}

Enemy &	Enemy::operator=(Enemy const & rhs) {

	this->_Type = rhs.getType();
	this->_HP = rhs.getHP();

	return *this;
}