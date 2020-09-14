/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:05:02 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:59:09 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include <stdexcept>

class Bureaucrat;
class Form;
class Intern;

class OfficeBlock
{
	private:
		Intern		*_Intern;
		Bureaucrat	*_Signer;
		Bureaucrat	*_Executor;
		OfficeBlock(OfficeBlock const & );
		OfficeBlock & operator=(OfficeBlock const &rhs);


	public:
		class InternAlreadyPresentException : public std::exception
		{
			public:
				InternAlreadyPresentException() throw();
				InternAlreadyPresentException(InternAlreadyPresentException const &) throw();
				virtual ~InternAlreadyPresentException() throw();
				InternAlreadyPresentException & operator=(InternAlreadyPresentException const &rhs) throw();
				virtual const char* what() const throw();
		};
		class SignerAlreadyPresentException : public std::exception
		{
			public:
				SignerAlreadyPresentException() throw();
				SignerAlreadyPresentException(SignerAlreadyPresentException const &) throw();
				virtual ~SignerAlreadyPresentException() throw();
				SignerAlreadyPresentException & operator=(SignerAlreadyPresentException const &rhs) throw();
				virtual const char* what() const throw();
		};
		class ExecutorAlreadyPresentException : public std::exception
		{
			public:
				ExecutorAlreadyPresentException() throw();
				ExecutorAlreadyPresentException(ExecutorAlreadyPresentException const &) throw();
				virtual ~ExecutorAlreadyPresentException() throw();
				ExecutorAlreadyPresentException & operator=(ExecutorAlreadyPresentException const &rhs) throw();
				virtual const char* what() const throw();
		};
		class BureaucratAlreadyPresentException : public std::exception
		{
			public:
				BureaucratAlreadyPresentException() throw();
				BureaucratAlreadyPresentException(BureaucratAlreadyPresentException const &) throw();
				virtual ~BureaucratAlreadyPresentException() throw();
				BureaucratAlreadyPresentException & operator=(BureaucratAlreadyPresentException const &rhs) throw();
				virtual const char* what() const throw();
		};
		class InternAlreadyPresentException : public std::exception
		{
			public:
				InternAlreadyPresentException() throw();
				InternAlreadyPresentException(InternAlreadyPresentException const &) throw();
				virtual ~InternAlreadyPresentException() throw();
				InternAlreadyPresentException & operator=(InternAlreadyPresentException const &rhs) throw();
				virtual const char* what() const throw();
		};
		class NotEnoughBureaucratException : public std::exception
		{
			public:
				NotEnoughBureaucratException() throw();
				NotEnoughBureaucratException(NotEnoughBureaucratException const &) throw();
				virtual ~NotEnoughBureaucratException() throw();
				NotEnoughBureaucratException & operator=(NotEnoughBureaucratException const &rhs) throw();
				virtual const char* what() const throw();
		};
		OfficeBlock();
		OfficeBlock(Intern *intern, Bureaucrat *sign, Bureaucrat *exec);
		virtual ~OfficeBlock();
		void	setIntern(Intern &intern);
		void	setSigner(Bureaucrat &signer);
		void	setExecutor(Bureaucrat &executor);
		void	doBureaucracy(std::string const form, std::string const target);
};

#endif