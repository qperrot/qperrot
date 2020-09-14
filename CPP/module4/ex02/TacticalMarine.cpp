/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:43:14 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/21 16:44:34 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for action !" << std::endl;
}
TacticalMarine::TacticalMarine(TacticalMarine const & src) {

	*this = src;	
}

TacticalMarine::~TacticalMarine() {

	std::cout <<  "Aaargh ..." << std::endl;
}

TacticalMarine &	TacticalMarine::operator=(TacticalMarine const & rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}

TacticalMarine* TacticalMarine::clone() const {

	TacticalMarine* nouveau = new TacticalMarine(*this);

	return nouveau;
}

void TacticalMarine::battleCry() const {

	std::cout << "For the Holy PLOT !" << std::endl;
}

void TacticalMarine::rangedAttack() const {

	std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const {

	std::cout << "* attacks with a chainsword *" << std::endl;
}