/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:23 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 15:56:37 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat& origin)
{
	*this = origin;
	std::cout << "Cat constructor by copy called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Cat& Cat::operator=(const Cat& origin)
{
	this->_type = origin._type;
	std::cout << "Cat constructror by assignation called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou !" << std::endl;
	return ;
}