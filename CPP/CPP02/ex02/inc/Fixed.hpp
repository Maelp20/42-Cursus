/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:21:07 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/10 13:35:51 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

public:
	//CONSTRUCTORS
	Fixed(void);
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed&);
	//DESTRUCTOR
	~Fixed(void);
	//MEMBER FUNCTIONS
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static Fixed& max(const Fixed& a, const Fixed& b);
	//OVERLOAD OPERATORS
	Fixed&	operator=(const Fixed&);
	Fixed&	operator+(const Fixed&);
	Fixed&	operator-(const Fixed&);
	Fixed&	operator*(const Fixed&);
	Fixed&	operator/(const Fixed&);
	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);
	bool	operator<(const Fixed&);
	bool	operator>(const Fixed&);
	bool	operator<=(const Fixed&);
	bool	operator>=(const Fixed&);
	bool	operator==(const Fixed&);
	bool	operator!=(const Fixed&);
private:
	int	_value;
	const static int	_fract_bits;
} ;

std::ostream&	operator<<(std::ostream& stream, const Fixed& entry);
#endif