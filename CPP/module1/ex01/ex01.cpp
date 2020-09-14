/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:26:08 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/05 15:36:19 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	memoryLeak()
{
	std::string* panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;

	delete panthere;
}

int		main( void ) {
	
	memoryLeak();
	return (0);
}