/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:13:21 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:57:17 by qperrot-         ###   ########.fr       */
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
		Form & operator=(Form const &rhs);
		std::string	const getName() const;
		int		getSignGrade() const;
		int		getExecGrade() const;
		bool	getSign() const;
		void	beSigne(const Bureaucrat &rhs);
		Form();
		Form(std::string const name, int const signGrad, int const execGrad);
		Form(Form const & );
		virtual ~Form();
};
std::ostream &		operator<<(std::ostream & o, Form const & i);



#endif