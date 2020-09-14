/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:10:59 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/12 10:19:32 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger () : _ofs("test.txt") {

	return ;
}

Logger::~Logger () {

	return ;
}

void 			Logger::logToConsole(std::string const & str) {

	std::cout << str << std::endl;
	return ;
}

void 			Logger::logToFile(std::string const & str) {

	if (!this->_ofs) {
		std::cout << "Error: fill failed to open" << std::endl;
		return ;
	}
	this->_ofs << str << std::endl;
	return ;
}

std::string 	Logger::makeLogEntry(std::string const & msg) {

	std::string		new_msg;
	std::string		date;
	time_t rawtime;

	time (&rawtime);
	date = ctime(&rawtime);
    new_msg.append(date.begin(), date.end() - 1);
	new_msg.append(" ");
	new_msg.append(msg);
	return (new_msg);
}

void			Logger::log(std::string const &dest, std::string const &message) {

	std::string		msg;
	int				index;
	msg = this->makeLogEntry(message);
	void	(Logger::* const fonction_array[2]) (std::string const & str) = {
			&Logger::logToConsole,
			&Logger::logToFile
	};
	index = (dest == "logToConsole") ? 0 : (dest == "logToFile") ? 1 : 2;
	(this->*fonction_array[index])(msg);
	return ;
}