/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:21:31 by qperrot-          #+#    #+#             */
/*   Updated: 2020/10/26 16:55:15 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
#define	TESTER_HPP

#include <algorithm>
#include <iterator>
#include <iostream>

#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <utility>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define STANDARD "\033[0m"
#define KO(str) std::cout << RED << str << STANDARD << std::endl; throw "END";
#define OK(str) std::cout << GREEN << str << STANDARD << std::endl;
#define COMP(real, me) std::cout << "real = " << std::endl; print_list(real); std::cout << " me = " << std::endl; print_list(me); compare_list(real, me);
#define COMP_MAP(real, me) std::cout << "real = " << std::endl; print_map(real); std::cout << " me = " << std::endl; print_map(me); compare_map(real, me);
#define COMP_QUEUE(real, me) std::cout << "real = " << std::endl; print_queue(real); std::cout << " me = " << std::endl; print_queue(me); compare_queue(real, me);
#define COMP_STACK(real, me) std::cout << "real = " << std::endl; print_stack(real); std::cout << " me = " << std::endl; print_stack(me); compare_stack(real, me);

template <class Container1, class Container2>
void compare(Container1 real, Container2 me)
{
	typename Container1::iterator it1 = real.begin();
	typename Container2::iterator it2 = me.begin();
		for (; it1 != real.end(); ++it1, ++it2)
		{
			if (*it1 != *it2)
			{
				KO("KO : differnet ele")
				return;
			}
		}
	OK("OK")
}

template <class Container1, class Container2>
void compare_list(Container1 og, Container2 me)
{
	if (og.size() != me.size())
	{
		std::cout << "og : " << og.size() << " me : " << me.size();
		KO("KO : different size")
		return;
	}
	typename Container1::iterator it1 = og.begin();
	typename Container2::iterator it2 = me.begin();
	if (og.size() != 0) {
		for (; it1 != og.end(); ++it1, ++it2)
		{
			if (*it1 != *it2)
			{
				KO("KO : differnet ele")
				return;
			}
		}
	}
	OK("OK")
}

template <class Container>
void print_list(Container c)
{
	typename Container::iterator it;
	std::cout << "eles : ";
	for (it = c.begin(); it != c.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <class Container>
void print_map(Container c)
{
	typename Container::iterator it;
	std::cout << "eles : ";
	for (it = c.begin(); it != c.end(); ++it)
	{
		std::cout << "(" << it->first << ", " << it->second << ") ";
	}
	std::cout << std::endl;
}

template <class Container1, class Container2>
void compare_map(Container1 real, Container2 me)
{
	if (real.size() != me.size())
	{
		std::cout << "real : " << real.size() << " me : " << me.size();
		KO("KO : different size")
		return;
	}
	typename Container1::iterator it1 = real.begin();
	typename Container2::iterator it2 = me.begin();
	if (real.size() != 0) {
		for (; it1 != real.end(); ++it1, ++it2)
		{
			if (it1->first != it2->first || it1->second != it2->second)
			{
				KO("KO : differnet ele")
				return;
			}
		}
	}
	OK("OK")
}

template <class Container>
void print_queue(Container c)
{
	std::cout << "eles : ";
	for (size_t i = 0; i < c.size(); i++)
  	{
		typename Container::value_type tmp = c.front();
    	std::cout << c.front() << " ";
    	c.pop();
		c.push(tmp);
 	 }
  std::cout << std::endl;
}

template <class Container1, class Container2>
void compare_queue(Container1 real, Container2 me)
{
	if (real.size() != me.size())
	{
		std::cout << "real : " << real.size() << " me : " << me.size();
		KO("KO : different size")
		return;
	}
	for (size_t i = 0; i < real.size(); i++)
	{
		typename Container1::value_type tmp_real = real.front();
		typename Container2::value_type tmp_me = me.front();
		if (tmp_real != tmp_me)
		{
			KO("KO : differnet ele")
		}
		real.pop();
		me.pop();
		real.push(tmp_real);
		me.push(tmp_me);
	}
	OK("OK")
}

template <class Container>
void print_stack(Container c)
{
	Container save;
	std::cout << "eles : ";
	for (size_t i = 0; i < c.size(); i++)
  	{
		typename Container::value_type tmp = c.top();
    	std::cout << tmp << " ";
    	c.pop();
		save.push(tmp);
 	}
	for (size_t i = 0; i < save.size(); i++)
  	{
		typename Container::value_type tmp = save.top();
		c.push(tmp);
		save.pop();
 	}
  std::cout << std::endl;
}

template <class Container1, class Container2>
void compare_stack(Container1 real, Container2 me)
{
	Container1 save_real;
	Container2 save_me;
	if (real.size() != me.size())
	{
		std::cout << "real : " << real.size() << " me : " << me.size();
		KO("KO : different size")
		return;
	}
	for (size_t i = 0; i < real.size(); i++)
	{
		typename Container1::value_type tmp_real = real.top();
		typename Container2::value_type tmp_me = me.top();
		if (tmp_real != tmp_me)
		{
			KO("KO : differnet ele")
		}
		real.pop();
		me.pop();
		save_real.push(tmp_real);
		save_me.push(tmp_me);
	}
	for (size_t i = 0; i < save_real.size(); i++)
  	{
		typename Container1::value_type tmp_real = save_real.top();
		typename Container2::value_type tmp_me = save_me.top();
		real.push(tmp_real);
		me.push(tmp_me);
		save_real.pop();
		save_me.pop();
 	}
  	std::cout << std::endl;
	OK("OK")
}

#endif