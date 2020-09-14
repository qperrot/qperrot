/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:13:08 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/27 17:54:56 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int const signGrad, int const execGrad, std::string const target) : _FName(name), _SignGrade(signGrad), _Sign(false), _ExecGrade(execGrad), _Target(target)
{
	if (signGrad < 1 || execGrad < 1)
		throw Form::GradeTooHighException();
	if (signGrad > 150 || execGrad > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : _FName(src.getName()), _SignGrade(src.getSignGrade()), _Sign(src.getSign()), _ExecGrade(src.getExecGrade()), _Target(src.getTarget()) {

	if (src.getSignGrade() < 1 || src.getExecGrade() < 1)
		throw Form::GradeTooHighException();
	if (src.getSignGrade() > 150 || src.getExecGrade() > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form & Form::operator=(Form const &rhs) {

	if (this == &rhs)
		return *this;
	this->_Sign = rhs.getSign();
	return *this;
}

std::string	const Form::getName() const {

	return this->_FName;
}

std::string	const Form::getTarget() const {

	return this->_Target;
}

int		Form::getSignGrade() const {

	return this->_SignGrade;
}
int		Form::getExecGrade() const {

	return this->_ExecGrade;
}
bool	Form::getSign() const {

	return this->_Sign;
}

Form::GradeTooHighException::GradeTooHighException() throw() {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src) throw() {

	(void)src;
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(GradeTooHighException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* Form::GradeTooHighException::what() const throw() {

	return "Exception Grade is too Hight.\n";
}

const char* Form::GradeTooLowException::what() const throw() {

	return "Exception Grade is too Low.\n";
}

Form::GradeTooLowException::GradeTooLowException() throw() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src) throw() {

	(void)src;
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(GradeTooLowException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}
Form::FormAlreadySignException::FormAlreadySignException() throw() {}

Form::FormAlreadySignException::~FormAlreadySignException() throw() {}

Form::FormAlreadySignException::FormAlreadySignException(FormAlreadySignException const &src) throw() {

	(void)src;
}

Form::FormAlreadySignException & Form::FormAlreadySignException::operator=(FormAlreadySignException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* Form::FormAlreadySignException::what() const throw() {

	return "Exception Form is Already Sign.\n";
}

Form::FormNotSignException::FormNotSignException() throw() {}

Form::FormNotSignException::~FormNotSignException() throw() {}

Form::FormNotSignException::FormNotSignException(FormNotSignException const &src) throw() {

	(void)src;
}

Form::FormNotSignException & Form::FormNotSignException::operator=(FormNotSignException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* Form::FormNotSignException::what() const throw() {

	return "Exception Form is Not Sign.\n";
}

void	Form::beSigne(const Bureaucrat &rhs) {

	// if (this->getSign())
	// 	throw Form::FormAlreadySignException();
	if (rhs.getGrade() <= this->getSignGrade())
		this->_Sign = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &		operator<<(std::ostream & o, Form const & i){

	o << i.getName();
	o << " , signature grade ";
	o << i.getSignGrade();
	o << " , execution grade ";
	o << i.getExecGrade();
	if (i.getSign())
		o << " is signed";
	else
		o << " is unsigned";
	o << std::endl;
	return o;
}