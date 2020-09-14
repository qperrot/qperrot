/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:11:13 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:52:34 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <ctime>
#include <time.h>

class Logger {
	private:
		void 			logToConsole(std::string const & str);
		void 			logToFile(std::string const & str);
		std::string 	makeLogEntry(std::string const & msg);
		std::ofstream	_ofs;

	public:
		Logger ( void );
		~Logger ( void );
		void	log(std::string const &dest, std::string const &message);
};

#endif