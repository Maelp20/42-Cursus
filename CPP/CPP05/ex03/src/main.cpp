/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:51:27 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/20 19:13:35 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{

	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat Jim("Jim", 140);
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	try
	{
		Jim.signForm(*rrf);
		Jim.executeForm(*rrf);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	try
	{
		Jim.signForm(*rrf);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	try
	{
		Jim.signForm(*rrf);
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}

	delete rrf;
	return (0);
}