/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:47:59 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/11 17:56:06 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void 	Human::meleeAttack(std::string const & target){

	std::cout << "Melee attack on " << target << std::endl;
}

void 	Human::rangedAttack(std::string const & target) {

	std::cout << "Range attack on " << target << std::endl;
}

void 	Human::intimidatingShout(std::string const & target) {

	std::cout << "Intimidating shout on " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target) {

	int				index;
	void	(Human::* const function_array[3])(std::string const & target) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};
	index = (action_name == "meleeAttack") ? 0 : (action_name == "rangedAttack") ? 1 : (action_name == "intimidatingShout") ? 2 : 3;
	if (index == 3)
		return ;
	(this->*function_array[index])(target);
}