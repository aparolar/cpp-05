/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:37:40 by aparolar          #+#    #+#             */
/*   Updated: 2022/11/08 22:09:14 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &toCopy)
	: Form(toCopy)
{
	*this = toCopy;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &toCopy)
{
	this->_target = toCopy.getTarget();
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!isSigned())
		throw Form::ExecuteException();
	else if (bureaucrat.getGrade() > getSignGrade())
		throw Form::GradeTooLowException();
	else
	{
		
		//srand(time(NULL));
		if (rand() % 2)
		{
			std::cout << "*Drilling noises in the background*" << std::endl;
			std::cout << this->getTarget() << " has been Robotomized succesfully" << std::endl;
		}
		else
			std::cout << this->getTarget() << " was not Robotomized :(" << std::endl;
	}
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (_target);
}
