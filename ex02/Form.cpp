/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:59:40 by aparolar          #+#    #+#             */
/*   Updated: 2022/11/08 19:10:12 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name(""),
	  _gradeToSign(150),
	  _gradeToExecute(150),
	  _isSigned(false)
{
}

Form::Form(Form const &toCopy)
	: _name(toCopy.getName()),
	  _gradeToSign(toCopy.getSignGrade()),
	  _gradeToExecute(toCopy.getExecuteGrade()),
	  _isSigned(false)
{
	*this = toCopy;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name),
	  _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute)
{
	_isSigned = false;
	if (gradeToSign < highGrade || gradeToExecute < highGrade)
		throw Form::GradeTooHighException();
	else if (gradeToSign > lowGrade || gradeToExecute > lowGrade)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form& Form::operator=(Form const &toCopy)
{
	this->_isSigned = toCopy.isSigned();
	return *this;
}

const std::string &Form::getName() const
{
	return (_name);
}

int Form::getSignGrade() const
{
	return (_gradeToSign);
}

int Form::getExecuteGrade() const
{
	return (_gradeToExecute);
}

bool Form::isSigned() const
{
	return (_isSigned);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= getSignGrade())
		_isSigned = true;
	bureaucrat.signForm(_isSigned, _name);
	if (bureaucrat.getGrade() > getSignGrade())
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

const char *Form::ExecuteException::what() const throw()
{
	return ("Form must be signed to be executed");
}

std::ostream &operator<<(std::ostream &out, Form const &toCopy)
{
	out << "Form " << toCopy.getName();
	out << " is grade " << toCopy.getSignGrade() << " and";
	if (toCopy.isSigned())
		out << " is signed";
	else
		out << " is not signed";
	return out;
}
