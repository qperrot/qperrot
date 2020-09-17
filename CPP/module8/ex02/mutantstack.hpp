/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:11:47 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/17 11:05:46 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <algorithm>

template< typename T >
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &src);
		virtual ~MutantStack();
		MutantStack& operator=(MutantStack const & rhs);

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin(void);
		iterator	end(void);
};

#endif