/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:12:59 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/10 13:28:25 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <iostream>

int	main(int argc, char **argv) {

	int		i;
	int		j;
	char	c;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			if (c >= 97 && c <= 122)
				c-= 32;
			std::cout << c;
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;

}
