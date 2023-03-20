/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:51:27 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/20 14:48:37 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	Jim = Bureaucrat("Jim", 145);
	Bureaucrat	Pam = Bureaucrat("Pam", 72);
	Bureaucrat	Dwight = Bureaucrat("Dwight", 25);
	Bureaucrat	Michael = Bureaucrat("Michael", 5);
	ShrubberyCreationForm Shrub("test");
	RobotomyRequestForm Robotomy("Kevin");
	PresidentialPardonForm Pardon("Mike");

	std::cout << Jim;
	std::cout << Pam;
	std::cout << Dwight;
	std::cout << Michael;
	std::cout << Shrub;
	std::cout << Robotomy;
	std::cout << Pardon;
	try
	{
		Jim.signForm(Shrub);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Jim.executeForm(Shrub);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Pam.executeForm(Shrub);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Pam.signForm(Robotomy);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Dwight.executeForm(Robotomy);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Pam.signForm(Pardon);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Dwight.signForm(Pardon);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Michael.executeForm(Pardon);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}