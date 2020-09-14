/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:38:12 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:52:20 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream> 

class Replace {

public:

	Replace ( const std::string fill, const std::string s1, const std::string s2 );
	~Replace ( void );
	int						check_arg(void) const;
	const std::string&		getfill( void ) const;
	void					setType(const std::string set_type);
	void					read_and_replace( void );


private:

	std::string		_fill;
	std::string		_s1;
	std::string		_s2;
};


#endif