/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:47:32 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/20 16:29:50 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

ScalarConverter::ScalarConverter(void) : _name("Anonymous"), _grade(150)
{
	std::cout << "Anonymous ScalarConverter created" << std::endl;
	return;
}

ScalarConverter::ScalarConverter(const std::string& name, const int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "ScalarConverter " << this->getName() << " created" << std::endl;
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	std::cout << "ScalarConverter created by copy" << std::endl;
	*this = src;
	return;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter " << this->_name << " destroyed" << std::endl;
	return;
}

/*--------------------------------OPERATORS-----------------------------------*/

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
	this->_grade = src._grade;
	std::cout << "ScalarConverter assignment operator called" << std::endl;
	return(*this);
}

std::ostream&	operator<<(std::ostream& o, const ScalarConverter& b)
{
	o << b.getName() << ", ScalarConverter grade " << b.getGrade() << ".";
	return(o);
}

/*--------------------------------ACCESSORS-----------------------------------*/

const std::string&	ScalarConverter::getName() const
{
	return(this->_name);
}

const int&	ScalarConverter::getGrade() const
{
	return(this->_grade);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/


void	ScalarConverter::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
	return;
}

void	ScalarConverter::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
	return;
}

/*--------------------------------EXCEPTIONS-----------------------------------*/

const char*	ScalarConverter::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high !");
}

const char*	ScalarConverter::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low !");
}