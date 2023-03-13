/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:23 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 15:12:52 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

WrongCat::WrongCat(void)
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat& origin)
{
	*this = origin;
	std::cout << "WrongCat constructor by copy called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

WrongCat& WrongCat::operator=(const WrongCat& origin)
{
	this->_type = origin._type;
	this->_brain = origin._brain;
	std::cout << "WrongCat constructror by assignation called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void WrongCat::makeSound() const
{
	std::cout << "Miewwww Miewwww !" << std::endl;
	return ;
}
