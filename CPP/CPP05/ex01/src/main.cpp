/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:51:27 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/20 16:30:43 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	John = Bureaucrat("John", 103);
	Form myForm = Form("myForm", 100, 90);

	std::cout << John << std::endl;
	std::cout << myForm << std::endl;
	try
	{
		Form badForm = Form("badForm", 170, 90);
		std::cout << badForm << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		John.signForm(myForm);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	John.incrementGrade();
	std::cout << John << std::endl;
	John.incrementGrade();
	std::cout << John << std::endl;
	John.incrementGrade();
	std::cout << John << std::endl;
	try
	{
		John.signForm(myForm);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		John.signForm(myForm);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}