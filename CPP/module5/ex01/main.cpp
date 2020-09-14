/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:06:36 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/27 14:29:06 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	
	Form	Form1("Form1", 23, 45);
	Form	Form2;
	Form	Form3(Form1);
	try
	{
		Form	Form4("Form4", 0, 120);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		Form	Form5("Form5", 2, 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Form*	Form6 = new Form("Form6", 24, 67);

	Form2 = Form1;
	std::cout << Form1;
	std::cout << Form2;
	std::cout << Form3;

	try
	{
		Form1.beSigne(John);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Form2.beSigne(Mike);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Lara.signForm(Form2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		John.signForm(Form3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Soso.signForm(*Form6);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
	delete Form6;
	return (0);
}