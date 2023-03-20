/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:51:27 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/20 16:34:26 by mpignet          ###   ########.fr       */
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
	PresidentialPardonForm Pardon("Prison Mike");

	std::cout << std::endl;
	std::cout << Jim << std::endl;
	std::cout << Pam << std::endl;
	std::cout << Dwight << std::endl;
	std::cout << Michael << std::endl;
	std::cout << Shrub << std::endl;
	std::cout << Robotomy << std::endl;
	std::cout << Pardon << std::endl;
	std::cout << std::endl;
	try
	{
		Jim.signForm(Shrub);
		Jim.executeForm(Shrub);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Pam.executeForm(Shrub);
		Pam.signForm(Robotomy);
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
		Michael.executeForm(Pardon);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Dwight.signForm(Pardon);
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
	std::cout << std::endl;
	return (0);
}