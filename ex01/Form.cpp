/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:59:40 by aparolar          #+#    #+#             */
/*   Updated: 2022/11/08 19:11:27 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name(""),
	  _gradeToSign(150) ,
	  _gradeToExecute(150),
	  _isSigned(false)
{
}

Form::Form(Form const &toCopy)
	: _name(toCopy.getName()),
	  _gradeToSign(toCopy.getGradeToSign()) ,
	  _gradeToExecute(toCopy.getGradeToExecute()),
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
	if (_gradeToSign < highGrade || _gradeToExecute < highGrade)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > lowGrade || _gradeToExecute > lowGrade)
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

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool Form::isSigned() const
{
	return (_isSigned);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= getGradeToSign())
		_isSigned = true;
	bureaucrat.signForm(_isSigned, _name);
	if (bureaucrat.getGrade() > getGradeToSign())
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

std::ostream &operator<<(std::ostream &out, Form const &toCopy)
{
	out << "Form " << toCopy.getName();
	out << " is grade " << toCopy.getGradeToSign() << " and";
	if (toCopy.isSigned())
		out << " is signed";
	else
		out << " is not signed";
	return out;
}
