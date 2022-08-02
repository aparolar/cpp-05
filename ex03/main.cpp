/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:07:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/08/02 08:28:57 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern	someRandomIntern;
	Form 	*rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << rrf << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery request", "Shru");
	std::cout << rrf << std::endl;
	rrf = someRandomIntern.makeForm("pardon request", "Killme");
	std::cout << rrf << std::endl;
	rrf = someRandomIntern.makeForm("random request", "random");
	std::cout << rrf << std::endl;

	return (0);
}
