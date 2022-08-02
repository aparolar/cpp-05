/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:37:36 by aparolar          #+#    #+#             */
/*   Updated: 2022/08/01 18:41:28 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw Form::ExecuteException();
	else if (executor.getGrade() > getSignGrade())
		throw Form::GradeTooLowException();
	else
	{
		std::cout << getTarget() << " has been pardoned by Rockie!" << std::endl;
	}
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return (_target);
}
