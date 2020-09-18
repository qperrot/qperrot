/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 09:48:01 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/18 09:53:16 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base {
	public:
		A();
		A(A const &src);
		A &operator=(A const &rhs);
		virtual ~A();
};

#endif