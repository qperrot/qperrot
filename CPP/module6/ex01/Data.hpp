/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:50:35 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/17 13:47:13 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <sstream>
#include <cstring>

struct Data 
{
    std::string s1;
    int n;
    std::string s2;
};

void *	serialize(void);
Data *	deserialize(void * raw);
#endif


