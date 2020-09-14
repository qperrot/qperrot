/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:38:12 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/25 17:22:52 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _Name(name) {

	for (int i = 0; i < 4; i++)
		this->_tab[i] = NULL;
}


Character::Character(Character const & src) {

	for ( int i = 0; i < 4; i++)
		if (this->_tab[i] != NULL)
			delete this->_tab[i];

	for ( int i = 0; i < 4; i++) {
		if (src._tab[i] != NULL)
			this->_tab[i] = src._tab[i];
		else
			this->_tab[i] = NULL;
	}
	*this = src;
}

Character::~Character() {

	for (int i = 0; i < 4; i++) {
		if (this->_tab[i] != NULL) {
			delete this->_tab[i];
		}
	}
}

Character &	Character::operator=(Character const & rhs) {

	if (this == &rhs)
		return *this;
	this->_Name = rhs.getName();
	for (int i = 0; i < 4; i++)
		this->_tab[i] = rhs._tab[i]->clone();
	return *this;
}

std::string const & Character::getName() const {

	return this->_Name;
}

void Character::equip(AMateria* m) {

	if (m == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (this->_tab[i] == NULL)
		{
			this->_tab[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {

	if (idx >= 4 || idx < 0)
		return;
	this->_tab[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {

	if (idx >= 4 || idx < 0 || this->_tab[idx] == NULL)
		return;
	this->_tab[idx]->use(target);
	return;
}