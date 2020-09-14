/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:37:55 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/12 09:27:45 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

Replace::Replace ( const std::string fill, const std::string s1, const std::string s2 ) : 
_fill(fill), _s1(s1), _s2(s2) {

	return ;
}

Replace::~Replace ( void ) {

	return ;
}

void	Replace::read_and_replace( void ) {

	std::ifstream	ifs(this->_fill);
	if (!ifs) {
		std::cout << "Error: fill failed to open" << std::endl;
		return ;
	}
	std::ofstream	ofs("FILENAME.replace");
	if (!ofs) {
		std::cout << "Error: fill failed to open" << std::endl;
		return ;
	}
	std::string		line;
	size_t			len = this->_s1.length();
	while(std::getline(ifs, line)){
		
		size_t	pos = line.find(this->_s1);
		while (pos != std::string::npos)
		{
			line.replace(pos, len, this->_s2);
			pos = line.find(this->_s1, pos + this->_s2.length());
		}
		ofs << line << std::endl;
		pos = line.find(this->_s1, pos + this->_s2.length());
	}
	ofs << std::endl;
	ifs.close();
	ofs.close();

}

int		Replace::check_arg(void) const {

	std::ifstream ifs;

	if (this->_s1.size() == 0 || this->_s2.size() == 0 || this->_fill.size() == 0) {
		std::cout << "Error: Empty string" << std::endl;
		return (1);
	}
	return (0);
}