/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:20:55 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/10 12:17:31 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fract_bits = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = n * (1 << this->_fract_bits);
	return ;
}

Fixed::Fixed(const float n)
{
	this->_value = roundf(n * (1 << this->_fract_bits));
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(const Fixed& entry)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = entry._value;
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& entry)
{
	stream << entry.toFloat();
	return (stream);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::toInt(void) const
{
	int	result;

	result = this->_value >> this->_fract_bits;
	return (result);	
}

float	Fixed::toFloat(void) const
{
	float result;

	result = (float)(this->_value) / (1 << this->_fract_bits);
	return (result);
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
