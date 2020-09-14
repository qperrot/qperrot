/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:28:18 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:58:09 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdexcept>

class Bureaucrat;
class Form;

class Intern
{
	private:
		std::string		_tab[3];

	public:
		class WrongNameException : public std::exception
		{
			public:
				WrongNameException() throw();
				WrongNameException(WrongNameException const &) throw();
				virtual ~WrongNameException() throw();
				WrongNameException & operator=(WrongNameException const &rhs) throw();
				virtual const char* what() const throw();
		};
		Intern & operator=(Intern const &rhs);
		Form*	CreatShruberyForm(std::string const target);
		Form*	CreatRobotomyForm(std::string const target);
		Form*	CreatPresidentialForm(std::string const target);
		Form*	makeForm(std::string const name, std::string const target);
		Intern();
		Intern(Intern const & );
		virtual ~Intern();
};

#endif