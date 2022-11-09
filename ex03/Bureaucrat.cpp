/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:31:35 by aparolar          #+#    #+#             */
/*   Updated: 2022/11/08 19:05:01 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &toCopy)
{
	*this = toCopy;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name),
	  _grade(grade)
{
	checkGrade();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &toCopy)
{
	this->_name = toCopy.getName();
	this->_grade = toCopy.getGrade();
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too hight");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too lower");
}

void Bureaucrat::checkGrade()
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooLowException();
}

std::string const &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::gradeUp()
{
	_grade++;
	checkGrade();	
}

void Bureaucrat::gradeDown()
{
	_grade--;
	checkGrade();
}

void Bureaucrat::signForm(const bool isSigned, const std::string formName)
{
	if (isSigned)
	{
		std::cout << "Bureaucrat " << this->getName() << " signed Form ";
		std::cout << formName << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat " << this->getName() << " could not sign Form ";
		std::cout << formName << " because he doesn't have enough grade" << std::endl;
	}
}

void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Could not execute form" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &toCopy)
{
	out << toCopy.getName();
	out << ", bureaucrat grade ";
	out << toCopy.getGrade();
	return out;
}
