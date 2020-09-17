/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:09:58 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 18:10:50 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T>
void print_array(Array<T> &src)
{
	for (unsigned int i = 0; i < src.size(); i++)
		std::cout << src[i] << " ";
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "Empty int" << std::endl;
	Array<int> tmp;
	std::cout << "size : " << tmp.size() << std::endl;
	std::cout <<  std::endl;
	std::cout << "NO Empty int" << std::endl;
	Array<int> tmp2(3);
	try
	{
		tmp2[0] = 42;
		tmp2[1] = 65;
		tmp2[2] = 20;
		std::cout << "size : " << tmp2.size() << std::endl;
		print_array(tmp2);
		tmp2[3] = 5;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout <<  std::endl;
	std::cout << "NO Empty float" << std::endl;
	Array<float> tmp3(3);
	try
	{
		tmp3[0] = 42.42;
		tmp3[1] = 65.6;
		tmp3[2] = 20.32;
		std::cout << "size : " << tmp3.size() << std::endl;
		print_array(tmp3);
		tmp3[3] = 5;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout <<  std::endl;
	std::cout << "NO Empty string" << std::endl;
	Array<std::string>  arrString(3);
	try
	{
		arrString[0] = "quentin";
		arrString[1] = "Max";
		arrString[2] = "Jack";
		std::cout << "size : " << arrString.size() << std::endl;
		print_array(arrString);
		arrString[3] = "Marc";
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout <<  std::endl;
	std::cout << "NO Empty string COPY" << std::endl;
	Array<std::string>  arrString2(arrString);
	print_array(arrString2);
	std::cout <<  std::endl;
	std::cout << "NO Empty string Assign" << std::endl;
	Array<std::string>  arrString3(3);
	arrString3 = arrString;
	print_array(arrString3);
	std::cout <<  std::endl;
	std::cout << "NO Empty char" << std::endl;
	Array<char> tmp4(3);
	try
	{
		tmp4[0] = 'a';
		tmp4[1] = 'b';
		tmp4[2] = 'c';
		std::cout << "size : " << tmp4.size() << std::endl;
		print_array(tmp4);
		tmp4[3] = 'd';
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}