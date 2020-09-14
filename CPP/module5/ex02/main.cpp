/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:06:36 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/27 17:40:10 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	John("John", 23);
	Bureaucrat	Mike;
	Bureaucrat	Lili(John);
	Bureaucrat	Lara("Lara", 1);
	Bureaucrat	Soso("Soso", 150);

	Mike = John;
	std::cout << John;
	std::cout << Mike;
	std::cout << Lili;
	std::cout << Lara;
	std::cout << Soso;
	try
	{
		John.increment();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Lara.increment();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Soso.decrement();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Bureaucrat* Karen = new Bureaucrat("Karen", 156);
		delete Karen;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Bureaucrat* Karen = new Bureaucrat("Karen", 0);
		delete Karen;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	
	ShrubberyCreationForm* Form1 = new ShrubberyCreationForm("maison");
	RobotomyRequestForm*	Form2 = new RobotomyRequestForm("Xavier");
	PresidentialPardonForm*	Form3 = new PresidentialPardonForm("Freddy");
	try
	{
		John.signForm(*Form1);
		Form1->execute(John);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Lara.signForm(*Form2);
		Form2->execute(Lara);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Soso.signForm(*Form3);
		Form3->execute(Soso);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete Form1;
	delete Form2;
	delete Form3;
	return (0);
}