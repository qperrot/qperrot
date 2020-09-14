/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:07:22 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:52:06 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream> 

class Weapon {

public:

	Weapon ( const std::string type );
	~Weapon ( void );
	const std::string&		getType( void ) const;
	void					setType(const std::string set_type);


private:

	std::string		_type;
};


#endif