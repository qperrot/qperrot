/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:31:56 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 11:00:08 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"

class Bureaucrat;

class Form;

class PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const & );
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm & operator=(PresidentialPardonForm const &rhs);
		virtual void execute (Bureaucrat const & executor) const;
};


#endif