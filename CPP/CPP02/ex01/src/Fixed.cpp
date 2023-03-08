/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:20:55 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/08 17:58:51 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	_fract_bits = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& nbr)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = nbr.getRawBits();
	return ;
}

Fixed::Fixed(const int n)
{
	
	return ;
}

Fixed::Fixed(const float n)
{
	
	return ;
}

Fixed&	Fixed::operator=(const Fixed& entry)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = entry.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

float	Fixed::toFloat(void) const
{
	float result;

	result = this->_value;
	return (result);
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_fract_bits);	
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	std::cout << "setRawBits member function called" << std::endl;
	return ;
}
