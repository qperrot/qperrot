/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:16:53 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:51:32 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"
#include <string>
#include <iostream>

class Human {

public:

	Human ( void );
	~Human ( void );
	std::string	identify( void ) const;
	const Brain&	getBrain( void ) const;

private:

	const Brain		_Brain;
};


#endif