/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:22:49 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/16 11:02:15 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

template< typename T >
int	easyfind(T& container, int i)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), i);
	if (iter != container.end())
	{
		std::cout << "the value " << *iter << " is present" << std::endl;
		return (0);
	}
	return (-1);
}


#endif