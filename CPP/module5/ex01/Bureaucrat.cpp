/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:06:27 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/27 17:56:56 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _Name("Default"), _Grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _Name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_Grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _Name(src.getName()){

	if (src.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	if (src.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_Grade = src.getGrade();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs) {

	if (this == &rhs)
		return *this;
	this->_Grade = rhs.getGrade();

	return *this;
}

std::string	const Bureaucrat::getName() const {

	return this->_Name;
}

int	Bureaucrat::getGrade() const {

	return this->_Grade;
}

void	Bureaucrat::increment() {

	if (this->_Grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_Grade -= 1;
}

void	Bureaucrat::decrement() {

	if (this->_Grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_Grade += 1;
}

void	Bureaucrat::signForm(Form & rhs) const {

	if (rhs.getSign() == true)
		throw Bureaucrat::FormAlreadySignException();
	else if (rhs.getSignGrade() >= this->getGrade())
	{
		std::cout << this->getName() << " signs " << rhs.getName() << std::endl;
		rhs.beSigne(*this);
		return;
	}
	else
		std::cout << this->getName() << " cant sign " << rhs.getName() << " because ";
	if (this->getGrade() > rhs.getSignGrade())
		throw Bureaucrat::GradeTooLowException();
		
}

Bureaucrat::GradeTooHighException::GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src) throw() {

	(void)src;
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {

	return "Exception Grade is too Hight.\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {

	return "Exception Grade is too Low.\n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src) throw() {

	(void)src;
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

Bureaucrat::FormAlreadySignException::FormAlreadySignException() throw() {}

Bureaucrat::FormAlreadySignException::~FormAlreadySignException() throw() {}

Bureaucrat::FormAlreadySignException::FormAlreadySignException(FormAlreadySignException const &src) throw() {

	(void)src;
}

Bureaucrat::FormAlreadySignException & Bureaucrat::FormAlreadySignException::operator=(FormAlreadySignException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* Bureaucrat::FormAlreadySignException::what() const throw() {

	return "Exception Form is Already Sign.\n";
}

std::ostream &		operator<<(std::ostream & o, Bureaucrat const & i){

	o << i.getName();
	o << " , bureaucrat grade ";
	o << i.getGrade();
	o << std::endl;
	return o;
}