/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:08:04 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/24 10:26:55 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include <unistd.h>

Squad::Squad() : _Unit(0), _Begin(NULL)
{
}

Squad::Squad(Squad const & src) {

	t_Unit	*unit;
	t_Unit	*next;

	unit = this->_Begin;
	next = this->_Begin->_next;
	for (int i=0; i < this->getCount(); i++)
	{
		delete unit;
		unit = next;
		next = unit->_next;
	}
	this->_Unit = 0;
	for (int i=0; i < src.getCount(); i++)
	{
		this->push((src.getUnit(i))->clone());
	}
	delete src._Begin;
}

Squad::~Squad()
{
	t_Unit	*next = NULL;

	for (int i=0; i < this->getCount(); i++)
	{
		next = this->_Begin->_next;
		delete this->_Begin->_Marine;
		delete this->_Begin;
		this->_Begin = next;
	}
}

Squad &	Squad::operator=(Squad const & rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}

int		Squad::getCount() const {

	return this->_Unit;
}

ISpaceMarine*	Squad::getUnit(int N) const {

	t_Unit	*current = NULL;
	if (N < 0 || N >= this->_Unit) {
		std::cout << "Error index" << std::endl;
		return NULL;
	}
	current = this->_Begin;
	for (int i = 0; i < N; i++) {
		current = current->_next;
	}
	return (current->_Marine);	
}

int		Squad::push(ISpaceMarine* rhs) {

	t_Unit	*current = NULL;

	if (rhs == NULL) {
		std::cout << "Error NULL Unit" << std::endl;
		return 1;
	}
	if (this->_Begin == NULL)
	{
		this->_Begin = new t_Unit;
		this->_Begin->_Marine = rhs;
		this->_Begin->_next = NULL;
		this->_Unit++;
		return (0);
	}
	current = this->_Begin;
	while (current->_next)
	{
		if (current->_Marine == rhs)
		{
			std::cout << "Error Unit already exists" << std::endl;
			return 1;
		}
		current = current->_next;
	}
	t_Unit *newnew = new t_Unit;
	newnew->_Marine = rhs;
	newnew->_next = NULL;
	current->_next = newnew;
	this->_Unit++;
	return 0;
}