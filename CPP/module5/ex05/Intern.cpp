/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:28:32 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/28 17:01:38 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {

	this->_tab[0] = "shrubbery creation";
	this->_tab[1] = "robotomy request";
	this->_tab[2] = "presidential pardon";
}

Intern::Intern(Intern const &src) {

	*this = src;
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const &rhs) {

	if (this == &rhs)
		return *this;
	this->_tab[0] = rhs._tab[0];
	this->_tab[1] = rhs._tab[1];
	this->_tab[2] = rhs._tab[2];
	return *this;
}

Intern::WrongNameException::WrongNameException() throw() {}

Intern::WrongNameException::~WrongNameException() throw() {}

Intern::WrongNameException::WrongNameException(WrongNameException const &src) throw() {

	(void)src;
}

Intern::WrongNameException & Intern::WrongNameException::operator=(WrongNameException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* Intern::WrongNameException::what() const throw() {

	return "Exception Name of Form is Unknow.\n";
}

Form*	Intern::CreatShruberyForm(std::string const target) {

	Form* Shrubbery = new ShrubberyCreationForm(target);
	std::cout << "Intern creates shrubbery creation Form (s.grade " << Shrubbery->getSignGrade() << " ex.grad " << Shrubbery->getExecGrade() << ") targeted on " << Shrubbery->getTarget();
	std::cout << " (";
	if (Shrubbery->getSign())
		std::cout << "Signe)" << std::endl;
	else
		std::cout << "Unsigne)" << std::endl;
	return Shrubbery;
}

Form*	Intern::CreatRobotomyForm(std::string const target) {

	Form* Robotomy = new RobotomyRequestForm(target);
	std::cout << "Intern creates robotomy request Form (s.grade " << Robotomy->getSignGrade() << " ex.grad " << Robotomy->getExecGrade() << ") targeted on " << Robotomy->getTarget();
	std::cout << " (";
	if (Robotomy->getSign())
		std::cout << "Signe)" << std::endl;
	else
		std::cout << "Unsigne)" << std::endl;
	return Robotomy;
}

Form*	Intern::CreatPresidentialForm(std::string const target) {

	Form* Presidential = new PresidentialPardonForm(target);
	std::cout << "Intern creates presidential pardon Form (s.grade " << Presidential->getSignGrade() << " ex.grad " << Presidential->getExecGrade() << ") targeted on " << Presidential->getTarget();
	std::cout << " (";
	if (Presidential->getSign())
		std::cout << "Signe)" << std::endl;
	else
		std::cout << "Unsigne)" << std::endl;
	return Presidential;
}

Form*	Intern::makeForm(std::string const name, std::string const target) {

	Form*	(Intern::* array[3]) (std::string const target) = {
		&Intern::CreatShruberyForm,
		&Intern::CreatRobotomyForm,
		&Intern::CreatPresidentialForm,
	};

	for (int i = 0; i < 3; i++)
	{
		if (this->_tab[i] == name)
			return (this->*array[i])(target);
	}
	throw Intern::WrongNameException();
}
