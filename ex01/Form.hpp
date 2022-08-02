/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:56:54 by aparolar          #+#    #+#             */
/*   Updated: 2022/08/01 17:07:25 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_isSigned;

		static const int	lowGrade = 150;
		static const int	highGrade = 1;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		~Form();

		const std::string &getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool isSigned() const;
		void beSigned(Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream    &operator<<(std::ostream &out, Form const &toCopy);

#endif