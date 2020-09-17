/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:05:19 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/16 16:17:11 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

void test_10000_numbers()
{
	Span sp = Span(10000);
	
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
		sp.addNumber(rand());
	std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "longest span = " << sp.longestSpan() << std::endl;
}

void default_test()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(-17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void already_full_exception()
{
	try
	{
		Span sp = Span(5);
		for (size_t i = 0; i < 6; i++)
			sp.addNumber(i);		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void no_span_found_exception()
{
	Span sp = Span(5);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	sp.addNumber(1);
	std::cout << sp.shortestSpan() << std::endl;
}

int main(void)
{
	std::cout << "default test" << std::endl;
	default_test();

	std::cout << "full exepction " << std::endl;
	already_full_exception();

	std::cout << "no span found exepction" << std::endl;
	no_span_found_exception();

	std::cout << "10000 numbers test" << std::endl;
	test_10000_numbers();
	return 0;
}