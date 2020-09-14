/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:06:36 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/26 15:10:47 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	
	return (0);
}