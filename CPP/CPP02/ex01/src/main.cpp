/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:20:51 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/08 13:57:41 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return (0);
}

/* int main(void)
{
	Fixed a;
	a.setRawBits(54);
	Fixed b( a );
	std::cout << a.getRawBits() << "(a)" << std::endl;
	std::cout << b.getRawBits() << "(b)" << std::endl;
	Fixed c;
	b.setRawBits(42);
	c = b;
	std::cout << a.getRawBits() << "(a)" << std::endl;
	std::cout << b.getRawBits() << "(b)" << std::endl;
	std::cout << c.getRawBits() << "(c)" << std::endl;
	b.setRawBits(-42);
	std::cout << b.getRawBits() << "(b)" << std::endl;
	std::cout << c.getRawBits() << "(c)" <<std::endl;
	return 0;
} */