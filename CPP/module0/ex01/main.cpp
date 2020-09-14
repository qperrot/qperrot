/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:13:26 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/14 14:29:27 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

int		execut_command(std::string buff, int numb_contact)
{
	if (buff.compare("ADD") == 0)
	{
		if (numb_contact >= MAX)
			return (4);
		return (1);
	}	
	else if (buff.compare("SEARCH") == 0)
		return (2);
	else if (buff.compare("EXIT") == 0)
		return (3);
	return (5);
}

void	print_list( void ) {

	std::cout << std::setw(11);
	std::cout << "index|";
	std::cout << std::setw(11);
	std::cout << "prenom|";
	std::cout << "nom de fa.|";
	std::cout << std::setw(11);
	std::cout << "pseudo|" << std::endl;
}

void	check_index(const Contact* contact, int numb_contact)
{
	std::string	line;
	int	 	index(1);

	while (numb_contact > 0)
	{
		if (std::cin.eof())
			break ;
		std::cout << "Enter index: ";
		std::getline (std::cin,line);
		if (line.length() != 1 || line.empty())
			std::cout << "Error Index" << std::endl;
		else
		{
			index = atoi(line.c_str());
			if (index < numb_contact) {
				contact[index].printIndex();
				break;
			}
			else
				std::cout << "Error Index" << std::endl;
		}
	}
}

int		main( void ) {

	Contact	contact[8];
	int		numb_contact;
	std::string	buff;

	numb_contact = 0;
	while (1)
	{
		if (std::cin.eof())
			return (0);
		std::cout << "\033[1;33mPhoneBook ~ \033[0m";
		std::getline (std::cin,buff);
		switch (execut_command(buff, numb_contact))
		{
			case 1 :
			{
				contact[numb_contact].addContact();
				numb_contact++;
				break;
			}

			case 2 :
			{
				print_list();
				for (int i = 0; i < numb_contact; i++)
					contact[i].listContact(i);
				check_index(contact, numb_contact);
				break ;
			}

			case 3 :
				return (0);

			case 4 :
			{
				std::cout << "You already have 8 contacts you can't have more" << std::endl;
				break;
			}

			default :
				std::cout << "Error Input" << std::endl;
				break;
		}
	}	
	
	return (0);
}
