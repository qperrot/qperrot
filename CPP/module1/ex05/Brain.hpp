/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:16:58 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:51:41 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream> 

class Brain {

public:

	Brain ( void );
	~Brain ( void );
	std::string	identify( void ) const;


private:

	// int		_size;
	// int		_weight;
	// int		_iq;
};


#endif