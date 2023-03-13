/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:20 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 15:14:50 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

WrongAnimal::WrongAnimal(void)
{
	this->_type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& origin)
{
	*this = origin;
	std::cout << "WrongAnimal constructor by copy called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& origin)
{
	this->_type = origin._type;
	std::cout << "WrongAnimal constructror by assignation called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void WrongAnimal::makeSound() const
{
	std::cout << "Weird animal sound..." << std::endl;
	return ;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}