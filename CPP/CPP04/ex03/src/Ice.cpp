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
	return ;
}

Ice::Ice(const Ice& origin)
{
	*this = origin;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Ice::~Ice(void)
{
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Ice& Ice::operator=(const Ice& origin)
{
	this->_type = origin.getType();
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}