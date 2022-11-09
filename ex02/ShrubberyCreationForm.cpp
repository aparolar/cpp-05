/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:37:46 by aparolar          #+#    #+#             */
/*   Updated: 2022/11/08 22:12:10 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &toCopy)
	: Form(toCopy)
{
	*this = toCopy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &toCopy)
{
	this->_target = toCopy.getTarget();
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!isSigned())
		throw Form::ExecuteException();
	else if (bureaucrat.getGrade() > getSignGrade())
		throw Form::GradeTooLowException();
	else
	{
		std::string fullName;
		fullName = this->_target + "_shruberry";
		std::fstream file(fullName.c_str(), std::ios::trunc | std::ios::out);
		file << ASCII_TREES;
		std::cout << "Form " << this->getName() << "  was executed succesfully!" << std::endl;
		file.close();
	}
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (_target);
}
