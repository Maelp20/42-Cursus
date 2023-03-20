/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:47:32 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/17 16:45:59 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm 42", 145, 137)
{
	std::cout << "ShrubberyCreationForm 42 created" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm 42", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " created" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
{
	*this = src;
	std::cout << "ShrubberyCreationForm created by copy" << std::endl;
	return;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " destroyed" << std::endl;
	return;
}

/*--------------------------------OPERATORS-----------------------------------*/

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	this->_target = src._target;
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	return(*this);
}

/*--------------------------------ACCESSORS-----------------------------------*/

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	outfile;

	this->check_exec(executor);
	outfile.open((this->_target + "_shrubbery").c_str());
	if (outfile.fail())
		throw CantOpenFileException();
	outfile << "      *" << std::endl;
	outfile << "     ***" << std::endl;
	outfile << "    *****" << std::endl;
	outfile << "   *******" << std::endl;
	outfile << "  *********" << std::endl;
	outfile << " ***********" << std::endl;
	outfile << "*************" << std::endl;
	outfile << "     |||" << std::endl;
	outfile.close();
	return;
}

/*--------------------------------EXCEPTIONS-----------------------------------*/

const char*	ShrubberyCreationForm::CantOpenFileException::what(void) const throw()
{
	return ("Can't open file !");
}