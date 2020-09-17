/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:05:30 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/16 16:49:43 by qperrot-         ###   ########.fr       */
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

		class FullException : public std::exception
		{
			// private:
			// 	IndexException() throw() {}
			// 	IndexException(IndexException const &) throw() {}
			// 	virtual ~IndexException() throw() {}
			// 	IndexException & operator=(IndexException const &rhs) throw() {}
			public:
				// IndexException() throw() {}
				// IndexException(IndexException const &) throw() {}
				// virtual ~IndexException() throw() {}
				// IndexException & operator=(IndexException const &rhs) throw() {}
				virtual const char* what() const throw() { return ("Span is full");};
		};
		class SpanonerangeException : public std::exception
		{
			// private:
			// 	IndexException() throw() {}
			// 	IndexException(IndexException const &) throw() {}
			// 	virtual ~IndexException() throw() {}
			// 	IndexException & operator=(IndexException const &rhs) throw() {}
			public:
				// IndexException() throw() {}
				// IndexException(IndexException const &) throw() {}
				// virtual ~IndexException() throw() {}
				// IndexException & operator=(IndexException const &rhs) throw() {}
				virtual const char* what() const throw() { return ("The Size of Span is 1 or empty so we can not compare values");};
		};
};

#endif