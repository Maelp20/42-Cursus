/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:20 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/14 14:08:07 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Ice::Ice(void)
{
	this->_type = "ice";
	std::cout << "Ice default constructor called" << std::endl;
	return ;
}

Ice::Ice(const Ice& origin)
{
	*this = origin;
	std::cout << "Ice constructor by copy called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Ice& Ice::operator=(const Ice& origin)
{
	(void)origin;
	std::cout << "Ice assignation operator called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

Ice* Ice::clone() const
{
	Ice*	newIce = new Ice();
	return (newIce);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target->_name << " *" << std::endl;
	return ;
}