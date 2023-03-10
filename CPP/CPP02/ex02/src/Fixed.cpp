/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:20:55 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/10 14:53:21 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fract_bits = 8;

/*-------------------------------CONSTRUCTORS---------------------------------*/

Fixed::Fixed(void) : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value = n * (1 << this->_fract_bits);
	return ;
}

Fixed::Fixed(const float n)
{
	this->_value = roundf(n * (1 << this->_fract_bits));
	//std::cout << "Float constructor called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Fixed&	Fixed::operator=(const Fixed& entry)
{
	if (this == &entry)
		return *this;
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_value = entry._value;
	return (*this);
}

Fixed&	Fixed::operator+(const Fixed& entry)
{
	this->_value = this->_value + entry._value;
	return (*this);
}

Fixed&	Fixed::operator-(const Fixed& entry)
{
	this->_value = this->_value - entry._value;
	return (*this);
}

Fixed&	Fixed::operator*(const Fixed& entry)
{
	this->_value = this->_value * entry.toFloat();
	return (*this);
}

Fixed&	Fixed::operator/(const Fixed& entry)
{
	this->_value = this->_value / entry.toFloat();
	return (*this);
}

Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_value++;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;

	this->_value--;
	return (temp);
}
bool	Fixed::operator<(const Fixed& entry)
{
	if (this->_value < entry._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>(const Fixed& entry)
{
	if (this->_value > entry._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed& entry)
{
	if (this->_value <= entry._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed& entry)
{
	if (this->_value >= entry._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed& entry)
{
	if (this->_value == entry._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed& entry)
{
	if (this->_value != entry._value)
		return (true);
	else
		return (false);
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& entry)
{
	stream << entry.toFloat();
	return (stream);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

int		Fixed::toInt(void) const
{
	int	result;

	result = this->_value >> this->_fract_bits;
	return (result);	
}

float	Fixed::toFloat(void) const
{
	float result;

	result = (float)(this->_value / (float)(1 << this->_fract_bits));
	return (result);
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	//std::cout << "setRawBits member function called" << std::endl;
	return ;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	//std::cout << "normal min" << std::endl;
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	//std::cout << "const min" << std::endl;
	if (a.toFloat() < b.toFloat())
	{
		Fixed& temp = (Fixed&)a;
		return (temp);
	}
	Fixed& temp = (Fixed&)b;
	return (temp);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	//std::cout << "normal max" << std::endl;
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	//std::cout << "const max" << std::endl;
	if (a.toFloat() > b.toFloat())
	{
		Fixed& temp = (Fixed&)a;
		return (temp);
	}
	Fixed& temp = (Fixed&)b;
	return (temp);
}