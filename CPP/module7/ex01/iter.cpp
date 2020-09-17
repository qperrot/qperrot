/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:27:16 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/17 14:39:35 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T >
void print(T const & n)
{
	std::cout << n << std::endl;
	return ;
}

template< typename T>
void iter(T *array, int len, void (*f)(T const & n))
{
	for (int i = 0; i < len; i++)
		f(array[i]);
}

int	main(void)
{
	int tab[] = {10, 42, 8, 109, 12}; 
	iter(tab, 5, &print);

	std::string tab1[] = {"Quentin", "Maxime", "Charlie"};
	iter(tab1, 3, &print);

	char tab2[] = {'a', 'b', 'c', 'd', 'e'};
	iter(tab2, 5, &print);

	float tab3[] = {42.32, 321.65, 12.9, 65.965};
	iter(tab3, 4, &print);

	return (0);
}