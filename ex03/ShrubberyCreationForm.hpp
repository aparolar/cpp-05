/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:37:49 by aparolar          #+#    #+#             */
/*   Updated: 2022/08/01 18:39:13 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

# define ASCII_TREES \
"               ,#######,						" << std::endl << \
"       ,,,.   ,######/##,  .oo8888o.			" << std::endl << \
"    ,O%%O%OO%,#####/######,8888\\88/8o			" << std::endl << \
"   ,%O\\%OO%OO%,###\\###/###88\\88888/88'		" << std::endl << \
"   %OO%O%O/%OO%##\\##/ /###88888\\88888'		" << std::endl << \
"   %OO%/ %O%%OO##\\ V /##' `88\\8 `/88'		" << std::endl << \
"   `O%\\ ` /%O'    |.|        \\ '|8'			" << std::endl << \
"       |o|        | |         | |				" << std::endl << \
"       |.|        | |         | |				" << std::endl << \
"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_	" << std::endl

class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		const std::string &getTarget() const;
		virtual void execute(Bureaucrat const &bureaucrat) const;
};

#endif
