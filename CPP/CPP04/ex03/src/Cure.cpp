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
	return ;
}

Cure::Cure(const Cure& origin)
{
	*this = origin;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Cure::~Cure(void)
{
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Cure& Cure::operator=(const Cure& origin)
{
	(void)origin;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

Cure* Cure::clone() const
{
	Cure*	newCure = new Cure();
	return (newCure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}