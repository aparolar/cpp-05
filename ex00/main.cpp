/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:07:29 by aparolar          #+#    #+#             */
/*   Updated: 2022/08/01 14:01:28 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat mike("Rockie", 0);
			std::cout << mike << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "|" << std::endl;

	{
		try
		{
			Bureaucrat jim("BobEsponja", 151);
			std::cout << jim << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "|" << std::endl;

	{	
		try 
		{
			Bureaucrat dur("MarioBros", 3);
			std::cout << dur << std::endl;
			dur.gradeUp();
			std::cout << dur << std::endl;
			dur.gradeUp();
			std::cout << dur << std::endl;
			dur.gradeUp();
			std::cout << dur << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "|" << std::endl;

	{	
		try 
		{
			Bureaucrat alan("AlexKid", 149);
			std::cout << alan << std::endl;
			alan.gradeDown();
			std::cout << alan << std::endl;
			alan.gradeDown();
			std::cout << alan << std::endl;
			alan.gradeDown();
			std::cout << alan << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	return (0);
}