/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:31:35 by aparolar          #+#    #+#             */
/*   Updated: 2022/11/08 16:46:03 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &toCopy)
{
	*this = toCopy;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &toCopy)
{
	out << toCopy.getName();
	out << ", bureaucrat grade ";
	out << toCopy.getGrade();
	return out;
}
