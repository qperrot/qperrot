/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:06:36 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/28 16:47:39 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main()
{
	Intern idiotOne;
	Bureaucrat Mike = Bureaucrat("Mike", 35);
	Bureaucrat Jack = Bureaucrat("Jack", 25);
	Bureaucrat Lili = Bureaucrat("Lili", 125);
	Bureaucrat Lara = Bureaucrat("Lara", 101);
	OfficeBlock ob;

	ob.setIntern(idiotOne);
	ob.setSigner(Lili);

	try
	{
		ob.doBureaucracy("shrubbery creation", "home");
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(char msg)
	{
		std::cerr << msg << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		ob.setExecutor(Lili);
	}
	catch(OfficeBlock::ExecutorAlreadyPresentException & e)
	{
		std::cerr << e.what();
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	ob.setExecutor(Mike);

	try
	{
		ob.doBureaucracy("shrubbery creation", "home");
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(char msg)
	{
		std::cerr << msg << std::endl;
	}

	std::cout << "---" << std::endl;

	ob.setExecutor(Lara);

	try
	{
		ob.doBureaucracy("presidential pardon", "Morty");
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(char const *msg)
	{
		std::cerr << msg << std::endl;
	}

	std::cout << "---" << std::endl;

	ob.setSigner(Jack);
	try
	{
		ob.doBureaucracy("presidential pardon", "Morty");
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(char msg)
	{
		std::cerr << msg << std::endl;
	}

	return (0);
}