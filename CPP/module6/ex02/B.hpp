/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 09:48:11 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/18 09:53:20 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base {
	public:
		B();
		B(B const &src);
		B &operator=(B const &rhs);
		virtual ~B();
};

#endif