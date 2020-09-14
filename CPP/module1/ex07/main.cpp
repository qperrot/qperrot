/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:54:03 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/11 11:03:28 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int		main(int argc, char **argv) {

	if (argc != 4) {
		std::cout << "Wrong numbers of arguments" << std::endl;
		return (1);
	}
	Replace		test = Replace(argv[1], argv[2], argv[3]);
	if (test.check_arg() == 1)
		return (1);
	test.read_and_replace();
	return (0);
}