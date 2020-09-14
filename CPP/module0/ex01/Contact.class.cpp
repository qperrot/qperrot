/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:13:09 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/14 15:02:46 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact( void ) : _first_name("empty"), _last_name("empty"), _nickname("empty"), _login("empty"), _post_add("empty"), _email("empty"), _phone("empty"), _birthday("empty"), _meal("empty"), _under_col("empty"), _secret("empty") {

	return ;
}

Contact::~Contact( void ) {

	return ;
}

void	Contact::addContact( void ) {

	std::cout << "Enter first name: ";
	std::getline (std::cin, this->_first_name);
	std::cout << "Enter last name: ";
	std::getline (std::cin,this->_last_name);
	std::cout << "Enter nickname: ";
	std::getline (std::cin,this->_nickname);
	std::cout << "Enter login: ";
	std::getline (std::cin,this->_login);
	std::cout << "Enter postal address: ";
	std::getline (std::cin,this->_post_add);
	std::cout << "Enter email address: ";
	std::getline (std::cin,this->_email);
	std::cout << "Enter phone number: ";
	std::getline (std::cin,this->_phone);
	std::cout << "Enter birthday date: ";
	std::getline (std::cin,this->_birthday);
	std::cout << "Enter favorite meal: ";
	std::getline (std::cin,this->_meal);
	std::cout << "Enter underwear color: ";
	std::getline (std::cin,this->_under_col);
	std::cout << "Enter darkest secret: ";
	std::getline (std::cin,this->_secret);
}

void	Contact::listContact( int i ) const {

	std::cout << std::setw(10);
	std::cout << i;
	std::cout << "|";
	if (this->_first_name.length() > 9)
	{
		std::string str2 = this->_first_name.substr (0,10);
		str2.replace(9, 1, ".");
		std::cout << str2;
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << this->_first_name;
	}
	std::cout << "|";
	if (this->_last_name.length() > 9)
	{
		std::string str2 = this->_last_name.substr (0,10);
		str2.replace(9, 1, ".");
		std::cout << str2;
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << this->_last_name;
	}
	std::cout << "|";
	if (this->_nickname.length() > 9)
	{
		std::string str2 = this->_nickname.substr (0,10);
		str2.replace(9, 1, ".");
		std::cout << str2;
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << this->_nickname;
	}
	std::cout << "|";
	std::cout << std::endl;
}

void	Contact::printIndex( void ) const {

	std::cout << this->_first_name << std::endl;
	std::cout << this->_last_name << std::endl;
	std::cout << this->_nickname << std::endl;
	std::cout << this->_login << std::endl;
	std::cout << this->_post_add << std::endl;
	std::cout << this->_email << std::endl;
	std::cout << this->_phone << std::endl;
	std::cout << this->_birthday << std::endl;
	std::cout << this->_meal << std::endl;
	std::cout << this->_under_col << std::endl;
	std::cout << this->_secret << std::endl;
}
