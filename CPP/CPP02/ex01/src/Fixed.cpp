/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:20:55 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 16:53:36 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
	return ;
}

Fixed::Fixed(const Fixed& nbr)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = nbr.getRawBits();
	return ;
}

Fixed::Fixed(const int n)
{
	
	return ;
}

Fixed&	Fixed::operator=(const Fixed& entry)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = entry.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
	std::cout << "setRawBits member function called" << std::endl;
	return ;
}