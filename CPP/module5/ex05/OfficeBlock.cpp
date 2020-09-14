/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:04:46 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/28 17:09:29 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : _Intern(NULL), _Signer(NULL), _Executor(NULL) {}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *sign, Bureaucrat *exec) :
_Intern(intern), _Signer(sign), _Executor(exec) {}

OfficeBlock::~OfficeBlock() {}

void	OfficeBlock::setIntern(Intern &intern) {

	if (&intern == this->_Intern)
		throw OfficeBlock::InternAlreadyPresentException();
	this->_Intern = &intern;
}

void	OfficeBlock::setSigner(Bureaucrat &signer) {

	if (&signer == this->_Executor)
		throw OfficeBlock::BureaucratAlreadyPresentException();
	this->_Signer = &signer;
}

void	OfficeBlock::setExecutor(Bureaucrat &executor) {

	if (&executor == this->_Signer)
		throw OfficeBlock::BureaucratAlreadyPresentException();
	this->_Executor = &executor;
}

void	OfficeBlock::doBureaucracy(std::string const form, std::string const target) {

	if (this->_Executor == NULL || this->_Intern == NULL || this->_Signer == NULL)
		throw OfficeBlock::NotEnoughBureaucratException();
	Form*	new_form;
	try
	{
		new_form = this->_Intern->makeForm(form, target);
		this->_Signer->signForm(*new_form);
		this->_Executor->executeForm(*new_form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw ("ERROR during Bureaucracy.\n");
	}
}

OfficeBlock::NotEnoughBureaucratException::NotEnoughBureaucratException() throw() {}

OfficeBlock::NotEnoughBureaucratException::~NotEnoughBureaucratException() throw() {}

OfficeBlock::NotEnoughBureaucratException::NotEnoughBureaucratException(NotEnoughBureaucratException const &src) throw() {

	(void)src;
}

OfficeBlock::NotEnoughBureaucratException & OfficeBlock::NotEnoughBureaucratException::operator=(NotEnoughBureaucratException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* OfficeBlock::NotEnoughBureaucratException::what() const throw() {

	return "Exception There is not enought people to do Bureaucracy\n";
}

OfficeBlock::InternAlreadyPresentException::InternAlreadyPresentException() throw() {}

OfficeBlock::InternAlreadyPresentException::~InternAlreadyPresentException() throw() {}

OfficeBlock::InternAlreadyPresentException::InternAlreadyPresentException(InternAlreadyPresentException const &src) throw() {

	(void)src;
}

OfficeBlock::InternAlreadyPresentException & OfficeBlock::InternAlreadyPresentException::operator=(InternAlreadyPresentException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* OfficeBlock::InternAlreadyPresentException::what() const throw() {

	return "Exception Intern is already present in this block.\n";
}

OfficeBlock::SignerAlreadyPresentException::SignerAlreadyPresentException() throw() {}

OfficeBlock::SignerAlreadyPresentException::~SignerAlreadyPresentException() throw() {}

OfficeBlock::SignerAlreadyPresentException::SignerAlreadyPresentException(SignerAlreadyPresentException const &src) throw() {

	(void)src;
}

OfficeBlock::SignerAlreadyPresentException & OfficeBlock::SignerAlreadyPresentException::operator=(SignerAlreadyPresentException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* OfficeBlock::SignerAlreadyPresentException::what() const throw() {

	return "Exception Signer is already present in this block.\n";
}

OfficeBlock::ExecutorAlreadyPresentException::ExecutorAlreadyPresentException() throw() {}

OfficeBlock::ExecutorAlreadyPresentException::~ExecutorAlreadyPresentException() throw() {}

OfficeBlock::ExecutorAlreadyPresentException::ExecutorAlreadyPresentException(ExecutorAlreadyPresentException const &src) throw() {

	(void)src;
}

OfficeBlock::ExecutorAlreadyPresentException & OfficeBlock::ExecutorAlreadyPresentException::operator=(ExecutorAlreadyPresentException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* OfficeBlock::ExecutorAlreadyPresentException::what() const throw() {

	return "Exception Executor is already present in this block.\n";
}

OfficeBlock::BureaucratAlreadyPresentException::BureaucratAlreadyPresentException() throw() {}

OfficeBlock::BureaucratAlreadyPresentException::~BureaucratAlreadyPresentException() throw() {}

OfficeBlock::BureaucratAlreadyPresentException::BureaucratAlreadyPresentException(BureaucratAlreadyPresentException const &src) throw() {

	(void)src;
}

OfficeBlock::BureaucratAlreadyPresentException & OfficeBlock::BureaucratAlreadyPresentException::operator=(BureaucratAlreadyPresentException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* OfficeBlock::BureaucratAlreadyPresentException::what() const throw() {

	return "Exception Bureaucrat is already present in this block.\n";
}

OfficeBlock::InternAlreadyPresentException::InternAlreadyPresentException() throw() {}

OfficeBlock::InternAlreadyPresentException::~InternAlreadyPresentException() throw() {}

OfficeBlock::InternAlreadyPresentException::InternAlreadyPresentException(InternAlreadyPresentException const &src) throw() {

	(void)src;
}

OfficeBlock::InternAlreadyPresentException & OfficeBlock::InternAlreadyPresentException::operator=(InternAlreadyPresentException const &rhs) throw() {

	if (this == &rhs)
		return *this;
	return *this;
}

const char* OfficeBlock::InternAlreadyPresentException::what() const throw() {

	return "Exception Intern is already present in this block.\n";
}