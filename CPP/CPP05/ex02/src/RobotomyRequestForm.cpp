/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:47:32 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/17 16:45:59 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm 42", 72, 45)
{
	std::cout << "RobotomyRequestForm 42 created" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm 42", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm " << this->getName() << " created" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
{
	*this = src;
	std::cout << "RobotomyRequestForm created by copy" << std::endl;
	return;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm " << this->getName() << " destroyed" << std::endl;
	return;
}

/*--------------------------------OPERATORS-----------------------------------*/

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	this->_target = src._target;
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	return(*this);
}

/*--------------------------------ACCESSORS-----------------------------------*/

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->check_exec(executor);
	std::srand((unsigned)time(NULL));
	int	random = std::rand();

	std::cout << "***Drilling noises***" << std::endl;
	if (random % 2 == 0)
		std::cout << "Robotomy failed !" << std::endl;
	else
		std::cout << this->_target << " has been robotomized successfully !" << std::endl;
	return;
}

/*--------------------------------EXCEPTIONS-----------------------------------*/

