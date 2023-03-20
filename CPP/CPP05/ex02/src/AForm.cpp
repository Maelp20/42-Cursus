/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:47:32 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/17 16:45:59 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

AForm::AForm(void) : _name("AForm 42"), _signGrade(150), _execGrade(150), _signed(false)
{
	std::cout << "AForm created" << std::endl;
	return;
}

AForm::AForm(const std::string& name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "AForm " << this->getName() << " created" << std::endl;
	return;
}

AForm::AForm(const AForm& src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _signed(false)
{
	std::cout << "AForm created by copy" << std::endl;
	return;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

AForm::~AForm(void)
{
	std::cout << "AForm " << this->_name << " destroyed" << std::endl;
	return;
}

/*--------------------------------OPERATORS-----------------------------------*/

AForm&	AForm::operator=(const AForm& src)
{
	(void)src;
	std::cout << "AForm assignment operator called" << std::endl;
	return(*this);
}

std::ostream&	operator<<(std::ostream& o, const AForm& AForm)
{
	o << AForm.getName() << ", form with sign grade " << AForm.getSignGrade();
	o << " and exec grade " << AForm.getExecGrade() << ".";
	return(o);
}

/*--------------------------------ACCESSORS-----------------------------------*/

const std::string&	AForm::getName() const
{
	return(this->_name);
}

const int&	AForm::getSignGrade() const
{
	return(this->_signGrade);
}

const int&	AForm::getExecGrade() const
{
	return(this->_execGrade);
}

bool	AForm::getSigned() const
{
	return(this->_signed);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/


void	AForm::beSigned(Bureaucrat& b)
{
	// std::cout << b.getName() << " 's grade :" << b.getGrade() << std::endl;
	// std::cout << this->getName() << " 's sign grade :" << this->getSignGrade() << std::endl;
	if (this->_signed == true)
		throw AForm::AlreadySignedException();
	else if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
	return ;
}

void	AForm::check_exec(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw AForm::TooLowToExecException();
	return ;
}

/*--------------------------------EXCEPTIONS-----------------------------------*/

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high !");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low !");
}

const char*	AForm::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed !");
}

const char*	AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form can't be executed because it's not signed !");
}

const char*	AForm::TooLowToExecException::what(void) const throw()
{
	return ("Grade too low !");
}