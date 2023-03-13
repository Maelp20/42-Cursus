/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:20 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 15:56:25 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Animal::Animal(void)
{
	this->_type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal& origin)
{
	*this = origin;
	std::cout << "Animal constructor by copy called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Animal& Animal::operator=(const Animal& origin)
{
	this->_type = origin._type;
	std::cout << "Animal constructror by assignation called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void Animal::makeSound() const
{
	std::cout << "Random animal sound..." << std::endl;
	return ;
}

std::string	Animal::getType() const
{
	return (this->_type);
}