/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 14:24:57 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/09 10:38:21 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {}

Convert::Convert(std::string num) : t_neg(false) {

	this->t_tab[0] = "nan";
	this->t_tab[1] = "nanf";
	this->t_tab[2] = "-inf";
	this->t_tab[3] = "-inff";
	this->t_tab[4] = "+inf";
	this->t_tab[5] = "+inff";
	switch(this->Parsing(num))
	{
		case 1:	
			this->t_int = static_cast<int>(this->getDouble());
			this->t_float = static_cast<float>(this->getDouble());
			if (this->getInt() >= 32 && this->getInt() < 127 )
				this->t_char = this->getInt();
			break;
		case 2:
			this->t_int = static_cast<int>(this->getChar());
			this->t_float = static_cast<float>(this->getChar());
			this->t_double = static_cast<double>(this->getChar());
			break;
		case 3:
			throw Convert::WrongConvException();
			break;
		case 4:
			throw (0);
	}
}
Convert::Convert(Convert const &src) : t_char(src.t_char), t_int(src.t_int), t_float(src.t_float),
t_double(src.t_double), t_neg(src.t_neg)
{
	this->t_tab[0] = src.t_tab[0];
	this->t_tab[1] = src.t_tab[1];
	this->t_tab[2] = src.t_tab[2];
	this->t_tab[3] = src.t_tab[3];
	this->t_tab[4] = src.t_tab[4];
	this->t_tab[5] = src.t_tab[5];
}

Convert & Convert::operator=(Convert const &rhs) {

	if (this == &rhs)
		return *this;
	this->t_neg = rhs.t_neg;
	this->t_int = rhs.t_int;
	this->t_char = rhs.t_char;
	this->t_float = rhs.t_float;
	this->t_double = rhs.t_double;
	this->t_tab[0] = rhs.t_tab[0];
	this->t_tab[1] = rhs.t_tab[1];
	this->t_tab[2] = rhs.t_tab[2];
	this->t_tab[3] = rhs.t_tab[3];
	this->t_tab[4] = rhs.t_tab[4];
	this->t_tab[5] = rhs.t_tab[5];
	return (*this);
}

Convert::~Convert() {}

int		Convert::Parsing(std::string num) {

	std::istringstream copy;

	for (int i = 0; i < 6; i++)
	{
		if (num == this->t_tab[i])
			return Printinf(num);
	}
	if (num[0] == '-')
		this->t_neg = true;
	for (size_t i = 0; i < num.length(); i++)
	{
		if (std::isdigit(num[i]))
		{
			for (size_t j = i; j < num.length() ; j++)
			{
				if (!std::isdigit(num[j]))
				{
					if ((num[j] == 'f' && !std::isdigit(num[j + 1])) ||
						(num[j] == '.' &&  std::isdigit(num[j + 1])) ||
						(num[j] == 'e' &&  std::isdigit(num[j + 1])) ||
						(num[j] == 'e' && num[j + 1] == '-') ||
						(num[j] == 'e' && num[j + 1] == '+') ||
						(num[j] == '-' && std::isdigit(num[j + 1])) ||
						(num[j] == '+' && std::isdigit(num[j + 1])))
						continue;
					else
						return 3;
				}
			}
			this->t_double = std::strtod(num.c_str(), NULL);
			return 1;
		}
		else if (num[i] > 32 && num[i] < 127)
		{
			if (num[i] == '-' && num.length() != i+1)
			{
				this->t_neg = true;
				continue;
			}
			if (num.length() == i+1)
			{
				this->t_char = num[i];
				return 2;
			}
			else
				break;
		}
	}
	return 3;
}

int		Convert::Printinf(std::string copy) const {

	if (copy == "nan" || copy == "nanf")
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "Int: impossible " << std::endl;
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
	}
	else
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "Int: impossible " << std::endl;
		if (copy == "-inf" || copy == "-inff")
		{
			std::cout << "Float: -inff" << std::endl;
			std::cout << "Double: -inf" << std::endl;
		}
		else
		{
			std::cout << "Float: +inff" << std::endl;
			std::cout << "Double: +inf" << std::endl;
		}
	}
	return 4;
}

void		Convert::PrintChar() const {

	if (this->getNeg() || this->getInt() < 32 || this->getInt() >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << this->getChar() << "'" << std::endl;
}

void		Convert::PrintInt() const {

	if (this->getDouble() > std::numeric_limits<int>::max() ||
		this->getDouble() < std::numeric_limits<int>::min())
		std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << this->getInt() << std::endl;
}

void		Convert::PrintFloat() const {

	std::ostringstream	ss;

	ss <<this->getFloat();
	std::string s(ss.str());
	if (s.find(".") == std::string::npos)
	{
		if (s.find("inf") == std::string::npos)
			std::cout << "Float: " <<this->getFloat() << ".0f" << std::endl;
		else if (this->getFloat() == std::numeric_limits<float>::max() ||
				this->getFloat() == std::numeric_limits<float>::min())
			std::cout << "Float: " <<this->getFloat() << std::endl;
		else
			std::cout << "Float: impossible" << std::endl;
	}
	else
		std::cout << "Float: " <<this->getFloat() << "f" << std::endl;
}

void		Convert::PrintDouble() const {

	std::ostringstream	ss;

	ss << this->getDouble();
	std::string s(ss.str());
	if (s.find(".") == std::string::npos)
	{
		if (s.find("inf") == std::string::npos)
			std::cout << "Double: " << this->getDouble() << ".0 " << std::endl;
		else if (this->getDouble() == std::numeric_limits<double>::max() ||
				this->getDouble() == std::numeric_limits<double>::min())
			std::cout << "Double: " << this->getDouble() << std::endl;
		else
			std::cout << "Double: impossible " << std::endl;
	}
	else
		std::cout << "Double: " << this->getDouble() << std::endl;
}

int		Convert::getInt() const { return this->t_int; }

float	Convert::getFloat() const { return this->t_float; }

double	Convert::getDouble() const { return this->t_double; }

char	Convert::getChar() const { return this->t_char; }

bool	Convert::getNeg() const { return this->t_neg; }

Convert::WrongConvException::WrongConvException() throw() {}

Convert::WrongConvException::~WrongConvException() throw() {}

Convert::WrongConvException::WrongConvException(WrongConvException const &src) throw() { (void)src; }

Convert::WrongConvException & Convert::WrongConvException::operator=(WrongConvException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* Convert::WrongConvException::what() const throw() {

	return "Error convertion is impossible.\n";
}