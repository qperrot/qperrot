/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 09:56:08 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/18 09:56:26 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B() {}

B::B(B const &src) { (void)src; }

B &B::operator=(B const &rhs) { (void)rhs; return (*this); }

B::~B() {};