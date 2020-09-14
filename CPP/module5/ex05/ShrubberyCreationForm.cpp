/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:30:36 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/27 17:42:37 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : Form("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {

	if (this == &rhs)
		return *this;
	return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

    if (!Form::getSign())
        throw Form::FormNotSignException();
    else if (Form::getExecGrade() < executor.getGrade())
        throw Form::GradeTooLowException();
    else
    {
        std::string     fill_name = Form::getTarget();
        std::ofstream   fill(fill_name += "_shrubbery");
        if (!fill)
            std::cout << "ERREUR: can not open Fill." << std::endl;
        else
        {
            fill << "                                   +                               " << std::endl;
            fill << "                                  +++                              " << std::endl;
            fill << "                                 +++++                             " << std::endl;
            fill << "                                +++++++                            " << std::endl;
            fill << "                               +++++++++                           " << std::endl;
            fill << "                              +++++++++++                          " << std::endl;
            fill << "                             +++++++++++++                         " << std::endl;
            fill << "                            +++++++++++++++                        " << std::endl;
            fill << "                           +++++++++++++++++                       " << std::endl;
            fill << "                         +++++++++++++++++++++                     " << std::endl;
            fill << "                            +++++++++++++++                        " << std::endl;
            fill << "                          +++++++++++++++++++                      " << std::endl;
            fill << "                        +++++++++++++++++++++++                    " << std::endl;
            fill << "                      +++++++++++++++++++++++++++                  " << std::endl;
            fill << "                    +++++++++++++++++++++++++++++++                " << std::endl;
            fill << "                  +++++++++++++++++++++++++++++++++++              " << std::endl;
            fill << "                +++++++++++++++++++++++++++++++++++++++            " << std::endl;
            fill << "                    +++++++++++++++++++++++++++++++                " << std::endl;
            fill << "                  +++++++++++++++++++++++++++++++++++              " << std::endl;
            fill << "                +++++++++++++++++++++++++++++++++++++++            " << std::endl;
            fill << "              +++++++++++++++++++++++++++++++++++++++++++          " << std::endl;
            fill << "            +++++++++++++++++++++++++++++++++++++++++++++++        " << std::endl;
            fill << "          +++++++++++++++++++++++++++++++++++++++++++++++++++      " << std::endl;
            fill << "                                 ++++++                            " << std::endl;
            fill << "                                 ++++++                            " << std::endl;
            fill << "                                 ++++++                            " << std::endl;
        }
        
    }
    
}