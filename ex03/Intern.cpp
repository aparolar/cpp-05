/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:07:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/11/09 10:35:09 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	 _formNameArray[0] = "shrubbery request";
	 _formNameArray[1] = "robotomy request";
	 _formNameArray[2] = "presidential request";
}

Intern::Intern(Intern const &toCopy)
{
	*this = toCopy;
}

Intern::~Intern()
{

}

Intern& Intern::operator=(Intern const &toCopy)
{
	for (int i = 0; i < 3; i++)
		this->_formNameArray[i] = toCopy._formNameArray[i];
	return *this;
}

Form *Intern::makeForm(const std::string &form, const std::string &target)
{
	ShrubberyCreationForm	sh(target);
	RobotomyRequestForm		ro(target);
	PresidentialPardonForm	pr(target);

	_formArray[0] = &sh;
	_formArray[1] = &ro;
	_formArray[2] = &pr;

	for (int i = 0; i < 3; i++)
	{
		if (_formNameArray[i] == form)
		{
			std::cout << "inter creates " << _formArray[i]->getName() << std::endl;
			return (_formArray[i]);
		}
	}
	std::cout << "Intern doesn't know " << form << std::endl;
	return (NULL);
}
