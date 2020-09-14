/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:31:04 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/27 17:27:14 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	if (!Form::getSign())
		throw Form::FormNotSignException();
	else if (Form::getExecGrade() < executor.getGrade())
		throw Form::GradeTooLowException();
	else
	{
		std::cout << "VRZZZZZZZZZ VRZZZZZZZZ VRZZZZZZ" << std::endl;
		std::cout << Form::getTarget() << " has been Robotomized" << std::endl;
	}
}