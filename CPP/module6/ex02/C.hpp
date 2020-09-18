/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 09:48:31 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/18 09:53:24 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base {
	public:
		C();
		C(C const &src);
		C &operator=(C const &rhs);
		virtual ~C();
};

#endif