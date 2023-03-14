/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:23 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 17:57:39 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
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
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Cat& Cat::operator=(const Cat& origin)
{
	this->_type = origin._type;
	*(this->_brain) = *(origin._brain);
	std::cout << "Cat assignation called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou !" << std::endl;
	return ;
}

Brain*	Cat::getBrain()
{
	return (this->_brain);
}