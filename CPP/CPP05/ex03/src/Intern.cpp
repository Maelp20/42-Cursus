/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:47:32 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/20 16:27:12 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Intern::Intern(void)
{
	std::cout << "Intern created" << std::endl;
	return;
}

Intern::Intern(const Intern& src)
{
	std::cout << "Intern created by copy" << std::endl;
	*this = src;
	return;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Intern::~Intern(void)
{
	std::cout << "Intern destroyed" << std::endl;
	return;
}

/*--------------------------------OPERATORS-----------------------------------*/

Intern&	Intern::operator=(const Intern& src)
{
	(void)src;
	std::cout << "Intern assignment operator called" << std::endl;
	return(*this);
}

/*--------------------------------ACCESSORS-----------------------------------*/

/*------------------------------MEMBER FUNCTIONS------------------------------*/

AForm* Intern::makeShrubberyCreation(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequest(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardon(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	t_form_types	form_t[] = {
		{"shrubbery creation", &Intern::makeShrubberyCreation},
		{"robotomy request", &Intern::makeRobotomyRequest},
		{"presidential pardon", &Intern::makePresidentialPardon}
	};
	for (int i = 0; i < 3; i++)
	{
		if(name == form_t[i].name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*(form_t[i].f))(target));
		}
	}
	std::cout << "Form of type " << name << " doesn't exist" << std::endl;
	return (NULL);
}

/*--------------------------------EXCEPTIONS-----------------------------------*/

