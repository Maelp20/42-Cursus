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

/*int main(void)
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
}*/

int main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed(1234.4321f);

	std::cout << std::endl;
	std::cout << "First we test our << operand, which calls our toFloat() function:" << std::endl;
	std::cout << "a is       " << a << std::endl;
	std::cout << "expected : 1234.43" << std::endl;
	std::cout << "b is       " << b << std::endl;
	std::cout << "expected : 10" << std::endl;
	std::cout << "c is       " << c << std::endl;
	std::cout << "expected : 42.4219" << std::endl;
	std::cout << "d is       " << d << std::endl;
	std::cout << "expected : 10" << std::endl << std::endl;

	std::cout << "Now testing our toInt() function, which converts Fixed point nbrs to integers:" << std::endl;
	std::cout << "a is       " << a.toInt() << " as integer" << std::endl;
	std::cout << "expected : 1234" << std::endl;
	std::cout << "b is       " << b.toInt() << " as integer" << std::endl;
	std::cout << "expected : 10" << std::endl;
	std::cout << "c is       " << c.toInt() << " as integer" << std::endl;
	std::cout << "expected : 42" << std::endl;
	std::cout << "d is       " << d.toInt() << " as integer" << std::endl;
	std::cout << "expected : 10" << std::endl << std::endl;
	return (0);
}