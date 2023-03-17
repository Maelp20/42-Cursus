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

int	main(void)
{
	Bureaucrat* test1;
	try
	{
		test1 = new Bureaucrat("test1", -1);
		std::cout << *test1;
		delete test1;
	}
	catch (Bureaucrat::GradeTooHighException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	try
	{
		test1 = new Bureaucrat("test1", 156);
		std::cout << *test1;
		delete test1;
	}
	catch (Bureaucrat::GradeTooHighException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	Bureaucrat* test2;
	try
	{
		test2 = new Bureaucrat("test2", 147);
		std::cout << *test2;
		test2->decrementGrade();
		std::cout << *test2;
		test2->decrementGrade();
		std::cout << *test2;
		test2->decrementGrade();
		std::cout << *test2;
		test2->decrementGrade();
		std::cout << *test2;
	}
	catch (Bureaucrat::GradeTooHighException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	delete test2;
	Bureaucrat* test3;
	try
	{
		test3 = new Bureaucrat("test3", 3);
		std::cout << *test3;
		test3->incrementGrade();
		std::cout << *test3;
		test3->incrementGrade();
		std::cout << *test3;
		test3->incrementGrade();
		std::cout << *test3;
		test3->incrementGrade();
		std::cout << *test3;
	}
	catch (Bureaucrat::GradeTooHighException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	delete test3;
	return (0);
}