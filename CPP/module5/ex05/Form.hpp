/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:13:21 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:59:54 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_FName;
		int	const			_SignGrade;
		bool				_Sign;
		int	const			_ExecGrade;
		std::string const 	_Target;
		Form();

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException() throw();
				GradeTooHighException(GradeTooHighException const &) throw();
				virtual ~GradeTooHighException() throw();
				GradeTooHighException & operator=(GradeTooHighException const &rhs) throw();
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException() throw();
				GradeTooLowException(GradeTooLowException const &) throw();
				virtual ~GradeTooLowException() throw();
				GradeTooLowException & operator=(GradeTooLowException const &rhs) throw();
				virtual const char* what() const throw();
		};
		class FormAlreadySignException : public std::exception
		{
			public:
				FormAlreadySignException() throw();
				FormAlreadySignException(FormAlreadySignException const &) throw();
				virtual ~FormAlreadySignException() throw();
				FormAlreadySignException & operator=(FormAlreadySignException const &rhs) throw();
				virtual const char* what() const throw();
		};
		class FormNotSignException : public std::exception
		{
			public:
				FormNotSignException() throw();
				FormNotSignException(FormNotSignException const &) throw();
				virtual ~FormNotSignException() throw();
				FormNotSignException & operator=(FormNotSignException const &rhs) throw();
				virtual const char* what() const throw();
		};
		Form & operator=(Form const &rhs);
		virtual std::string	const getTarget() const;
		virtual std::string	const getName() const;
		virtual int		getSignGrade() const;
		virtual int		getExecGrade() const;
		virtual bool	getSign() const;
		virtual void	beSigne(const Bureaucrat &rhs);
		virtual void execute(Bureaucrat const & executor) const = 0;
		Form(std::string const name, int const signGrad, int const execGrad, std::string const target);
		Form(Form const & );
		virtual ~Form();
};
std::ostream &		operator<<(std::ostream & o, Form const & i);



#endif