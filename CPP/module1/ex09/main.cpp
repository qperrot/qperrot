/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:10:39 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/12 10:22:16 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int		main( void )
{
	Logger	Log;

	Log.log("logToConsole", "qperrot");
	Log.log("logToFile", "qperrot");
	Log.log("logToConsole", "I like 42 and i like c++");
	Log.log("logToFile", "I like 42 and i like c++");
	Log.log("logToConsole", "This is a long log not just a simple log but a long log may be a little bite too long");
	Log.log("logToFile", "This is a long log not just a simple log but a long log may be a little bite too long");
	return (0);
}