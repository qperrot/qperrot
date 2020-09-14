/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 09:26:48 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/11 10:23:22 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void) {

	int	n = rand() % 3;
	if (n == 0)
		return (new A);
	else if (n == 1)
		return (new B);
	return (new C);
}

void identify_from_pointer(Base * p) {

	if (A* derived = dynamic_cast<A*>(p))
		std::cout << "real type is A" << std::endl;
	else if (B* derived = dynamic_cast<B*>(p))
		std::cout << "real type is B" << std::endl;
	else if (C* derived = dynamic_cast<C*>(p))
		std::cout << "real type is C" << std::endl;
	return ;
}

void identify_from_reference(Base & p) {

	identify_from_pointer(&p);
}