/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:31:39 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/27 17:23:53 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : Form("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {

	if (!Form::getSign())
		throw Form::FormNotSignException();
	else if (Form::getExecGrade() < executor.getGrade())
		throw Form::GradeTooLowException();
	else
		std::cout << Form::getTarget() << " is forgiven by Zafod Beeblebrox" << std::endl;
	
}