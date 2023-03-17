/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:20 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/14 14:08:07 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

AMateria::AMateria(void) : _type("AMateria")
{
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	return ;
}

AMateria::AMateria(const AMateria& origin)
{
	*this = origin;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

AMateria::~AMateria(void)
{
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

AMateria& AMateria::operator=(const AMateria& origin)
{
	this->_type = origin.getType();
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

const std::string&	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	return ;
}