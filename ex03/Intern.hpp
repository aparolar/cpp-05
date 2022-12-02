/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:07:33 by aparolar          #+#    #+#             */
/*   Updated: 2022/12/02 15:24:46 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

class Form;

class Intern
{
	private:
		std::string	_formNameArray[3];
		Form		*_formArray[3];
	
	public:
		Intern();
		Intern(Intern const &toCopy);
		~Intern();

		Intern& operator=(Intern const &toCopy);
		
		Form *makeForm(const std::string &form, const std::string &target);
};

#endif
