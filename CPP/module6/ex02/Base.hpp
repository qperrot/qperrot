/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 09:26:44 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/18 09:57:05 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <sstream>
#include <string>

class Base
{
	public:
		virtual ~Base() {};
};

Base * generate(void);
void identify_from_pointer(Base * p);
void identify_from_reference( Base & p);

#endif