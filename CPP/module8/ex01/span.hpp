/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:05:30 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/17 15:10:01 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <algorithm>
#include <iostream>
#include <exception>
#include <list>

class Span
{
	private:
		std::multiset<int>	_tab;
		unsigned int		_N;
		Span();
		
	public:
		Span(unsigned int N);
		Span(Span const & src);
		~Span();
		Span & operator=(Span const &rhs);
		void			addNumber(unsigned int);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};

#endif