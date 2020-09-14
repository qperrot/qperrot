/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:13:17 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/11 14:01:28 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>
#include <iostream>
#include <iomanip> 
#define MAX 8
class Contact {

public:

	Contact( void );
	~Contact( void );

	void	addContact( void );
	void	listContact( int i ) const;
	void	printIndex( void ) const;

private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_login;
	std::string	_post_add;
	std::string	_email;
	std::string	_phone;
	std::string	_birthday;
	std::string	_meal;
	std::string	_under_col;
	std::string	_secret;
};

#endif
