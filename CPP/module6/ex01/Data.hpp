/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:50:35 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 11:00:47 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <sstream>

struct Data 
{
    std::string s1;
    int n;
    std::string s2;
};

void *	serialize(void);
Data *	deserialize(void * raw);
#endif


