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
	std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria constructor by string called" << std::endl;
	return ;
}

AMateria::AMateria(const AMateria& origin)
{
	*this = origin;
	std::cout << "AMateria constructor by copy called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

AMateria& AMateria::operator=(const AMateria& origin)
{
	(void)origin;
	std::cout << "AMateria assignation operator called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

std::string	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	return ;
}