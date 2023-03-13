/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:26 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 15:56:44 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Dog::Dog(void)
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog& origin)
{
	*this = origin;
	std::cout << "Dog constructor by copy called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Dog& Dog::operator=(const Dog& origin)
{
	this->_type = origin._type;
	std::cout << "Cat constructror by assignation called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void Dog::makeSound() const
{
	std::cout << "Bark Bark !" << std::endl;
	return ;
}