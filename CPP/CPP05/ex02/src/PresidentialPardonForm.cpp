/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:47:32 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/17 16:45:59 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm 42", 25, 5)
{
	std::cout << "PresidentialPardonForm 42 created" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm 42", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm " << this->getName() << " created" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
{
	*this = src;
	std::cout << "PresidentialPardonForm created by copy" << std::endl;
	return;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm " << this->getName() << " destroyed" << std::endl;
	return;
}

/*--------------------------------OPERATORS-----------------------------------*/

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	this->_target = src._target;
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	return(*this);
}

/*--------------------------------ACCESSORS-----------------------------------*/

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->check_exec(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
	return;
}

/*--------------------------------EXCEPTIONS-----------------------------------*/

