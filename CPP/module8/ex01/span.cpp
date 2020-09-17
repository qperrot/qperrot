/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:05:07 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/16 16:06:01 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const & src) : _tab(src._tab), _N(src._N) {}

Span::~Span() {}

Span & Span::operator=(Span const &rhs) {

	if (this == &rhs)
		return *this;
	this->_tab = rhs._tab;
	this->_N = rhs._N;
	return (*this);
}

void			Span::addNumber(unsigned int num) {

	if (this->_tab.size() <= this->_N)
		this->_tab.insert(num);
	else
		throw Span::FullException();
}

unsigned int	Span::shortestSpan() {

	int				shortest;
	unsigned int	max;
	unsigned int	min;
	unsigned int	num;
	int	itnum;

	shortest = -1;
	if (_tab.size() <= 1)
		throw Span::SpanonerangeException();
	std::multiset<int>::iterator it=_tab.begin();
	while (it!=_tab.end())
	{
		itnum = *it;
		it++;
		for (std::multiset<int>::iterator iter=it; iter!=_tab.end(); iter++)
		{
			max = std::max(itnum, *iter);
			min = std::min(itnum, *iter);
			num = max - min;
			if (shortest == -1 || static_cast<unsigned>(shortest) > num)
				shortest = num;
		}
	}
	return (static_cast<unsigned>(shortest));
	
	
}

unsigned int	Span::longestSpan() {

	if (_tab.size() <= 1)
		throw Span::SpanonerangeException();
	return (*(--_tab.end()) - *_tab.begin());
}
