/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:47:32 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/17 16:45:59 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Form::Form(void) : _name("Form 42"), _signGrade(150), _execGrade(150), _signed(false)
{
	std::cout << "Form 42 created" << std::endl;
	return;
}

Form::Form(const std::string& name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form " << this->getName() << " created" << std::endl;
	return;
}

Form::Form(const Form& src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _signed(false)
{
	std::cout << "Form created by copy" << std::endl;
	return;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Form::~Form(void)
{
	std::cout << "Form " << this->_name << " destroyed" << std::endl;
	return;
}

/*--------------------------------OPERATORS-----------------------------------*/

Form&	Form::operator=(const Form& src)
{
	(void)src;
	std::cout << "Form assignment operator called" << std::endl;
	return(*this);
}

std::ostream&	operator<<(std::ostream& o, const Form& form)
{
	o << form.getName() << ", Form with sign grade " << form.getSignGrade();
	o << " and exec grade " << form.getExecGrade() << "." << std::endl;
	return(o);
}

/*--------------------------------ACCESSORS-----------------------------------*/

const std::string&	Form::getName() const
{
	return(this->_name);
}

const int&	Form::getSignGrade() const
{
	return(this->_signGrade);
}

const int&	Form::getExecGrade() const
{
	return(this->_execGrade);
}

bool	Form::getSigned() const
{
	return(this->_signed);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/


void	Form::beSigned(Bureaucrat& b)
{
	if (this->_signed == true)
		throw Form::AlreadySignedException();
	else if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
	return ;
}

/*--------------------------------EXCEPTIONS-----------------------------------*/

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high !");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low !");
}

const char*	Form::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed !");
}