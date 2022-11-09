/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:31:30 by aparolar          #+#    #+#             */
/*   Updated: 2022/11/09 10:33:45 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string _name;
		int			_grade;
		void checkGrade();
	
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &toCopy);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat& operator=(Bureaucrat const &toCopy);

		std::string const &getName() const;
		int getGrade() const;
		void gradeUp();
		void gradeDown();
		void signForm(const bool isSigned, const std::string formName);
		void executeForm(Form const & form);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream    &operator<<(std::ostream &out, Bureaucrat const &toCopy);

#endif
