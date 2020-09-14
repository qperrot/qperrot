/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:06:10 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:57:27 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const 	_Name;
		int					_Grade;

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
		Bureaucrat();
		Bureaucrat(Bureaucrat const &);
		Bureaucrat(std::string const name, int grade);
		virtual ~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const &rhs);
		std::string	const getName() const;
		int		getGrade() const;
		void	increment();
		void	decrement();
		void	signForm(Form &) const;
		void	executeForm(Form const & Form) const;
};
std::ostream &		operator<<(std::ostream & o, Bureaucrat const & i);


#endif