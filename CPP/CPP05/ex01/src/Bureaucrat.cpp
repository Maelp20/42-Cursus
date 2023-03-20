/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:47:32 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/20 16:29:30 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Bureaucrat::Bureaucrat(void) : _name("Anonymous"), _grade(150)
{
	std::cout << "Anonymous Bureaucrat created" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << this->getName() << " created" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	std::cout << "Bureaucrat created by copy" << std::endl;
	*this = src;
	return;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
	return;
}

/*--------------------------------OPERATORS-----------------------------------*/

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	this->_grade = src._grade;
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	return(*this);
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return(o);
}

/*--------------------------------ACCESSORS-----------------------------------*/

const std::string&	Bureaucrat::getName() const
{
	return(this->_name);
}

const int&	Bureaucrat::getGrade() const
{
	return(this->_grade);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/


void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
	return;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
	return;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
	return ;
}

/*--------------------------------EXCEPTIONS-----------------------------------*/

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high !");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low !");
}