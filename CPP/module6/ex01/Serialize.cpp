/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:15:30 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/10 16:10:06 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void *	serialize(void)
{
	int					n;
	std::stringstream	ss;
	std::string 		s1;
	std::string 		s2;
	std::string			random("ABCDEFghijk123456789");

	srand(time(NULL));
	for (int i = 0; i < 8; i++)
	{
		s1 += random[rand() % 20];
		s2 += random[rand() % 20];
	}
	n = rand() % 200;
	ss << s1 << n << s2;
	char		*test = new char[ss.str().length()];
	ss >> test;
	return (static_cast<void*>(test));
}

Data *	deserialize(void *raw)
{
	Data				*src = new Data;
	char				*buff = reinterpret_cast<char*>(raw);
	std::stringstream	ss;

	src->s1 = std::string(buff, 8);
	ss << std::string(buff + 8, std::strlen(buff) - 16);	
	ss >> src->n;
	src->s2 = std::string(buff + std::strlen(buff) - 8, 8);
	delete buff;
	return src;
}