/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:22:43 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/16 11:03:32 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::cout << "TEST LIST" << std::endl;
	std::cout << std::endl;
	std::list<int>	lst1;
	lst1.push_back(1);
	lst1.push_back(17);
	lst1.push_back(21);
	lst1.push_back(4);
	lst1.push_back(43);
	if (easyfind(lst1, 21) == -1)
		std::cout << "Occurence not found" << std::endl;
	std::cout << std::endl;

	std::cout << "TEST LIST WITH NO OCCURENCE" << std::endl;
	std::cout << std::endl;
	lst1.clear();
	lst1.push_back(1);
	lst1.push_back(17);
	lst1.push_back(22);
	lst1.push_back(4);
	lst1.push_back(43);
	if (easyfind(lst1, 21) == -1)
		std::cout << "Occurence not found" << std::endl;
	std::cout << std::endl;

	std::cout << "TEST VECTOR" << std::endl;
	std::cout << std::endl;
	std::vector<int> myvector;
	myvector.push_back(64);
	myvector.push_back(42);
	myvector.push_back(1);
	myvector.push_back(9);
	myvector.push_back(9);
	if (easyfind(myvector, 9) == -1)
		std::cout << "Occurence not found" << std::endl;
	std::cout << std::endl;
	std::cout << "TEST VECTOR WITH NO OCCURENCE" << std::endl;
	std::cout << std::endl;
	myvector.clear();
	myvector.push_back(64);
	myvector.push_back(42);
	myvector.push_back(1);
	myvector.push_back(8);
	myvector.push_back(2);
	if (easyfind(myvector, 9) == -1)
		std::cout << "Occurence not found" << std::endl;
	std::cout << std::endl;

	std::cout << "TEST DEQUE" << std::endl;
	std::cout << std::endl;
	std::deque<int> mydeque;
	mydeque.push_back(0);
	mydeque.push_back(54);
	mydeque.push_back(1000);
	mydeque.push_back(7);
	mydeque.push_back(3);
	if (easyfind(mydeque, 1000) == -1)
		std::cout << "Occurence not found" << std::endl;
	std::cout << std::endl;
	std::cout << "TEST DEQUE WITH NO OCCURENCE" << std::endl;
	std::cout << std::endl;
	mydeque.clear();
	mydeque.push_back(6);
	mydeque.push_back(4);
	mydeque.push_back(19);
	mydeque.push_back(80);
	mydeque.push_back(25);
	if (easyfind(mydeque, 9) == -1)
		std::cout << "Occurence not found" << std::endl;
	return (0);
}