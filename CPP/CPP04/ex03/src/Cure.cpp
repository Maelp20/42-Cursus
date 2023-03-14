/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:20 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/14 14:08:07 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Cure::Cure(void)
{
	this->_type = "cure";
	std::cout << "Cure default constructor called" << std::endl;
	return ;
}

Cure::Cure(const Cure& origin)
{
	*this = origin;
	std::cout << "Cure constructor by copy called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Cure& Cure::operator=(const Cure& origin)
{
	(void)origin;
	std::cout << "Cure assignation operator called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

Cure* clone() const
{
	Cure*	newCure = new Cure();
	return (newCure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target->_name << "'s wounds *" << std::endl;
	return ;
}