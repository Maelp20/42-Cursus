/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:51:27 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/17 16:49:34 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	John = Bureaucrat("John", 103);
	Form myForm = Form("myForm", 100, 90);

	std::cout << John;
	std::cout << myForm;
	try
	{
		Form badForm = Form("badForm", 170, 90);
		std::cout << badForm;
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
	std::cout << John;
	John.incrementGrade();
	std::cout << John;
	John.incrementGrade();
	std::cout << John;
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