/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:20:51 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/10 15:54:18 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/* int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
} */

int main(void)
{
	float	nbr = 0.4516;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c;
	Fixed d( Fixed( 15.05f ) / Fixed( 3 ) );
	Fixed e( Fixed( 15.05f ) + Fixed( 3 ) );
	Fixed f( Fixed( 15.05f ) - Fixed( 3 ) );
	Fixed g(nbr);

	std::cout << "Testing constructions and + - * / operators :" << std::endl << std::endl;
	std::cout << "a =        " << a << std::endl;
	std::cout << "expected : 0" << std::endl;
	std::cout << "b =        " << b << std::endl;
	std::cout << "expected : 10.1016" << std::endl;
	std::cout << "c =        " << c << std::endl;
	std::cout << "expected : 0" << std::endl;
	std::cout << "d =        " << d << std::endl;
	std::cout << "expected : 5.01562" << std::endl;
	std::cout << "e =        " << e << std::endl;
	std::cout << "expected : 18.0508" << std::endl;
	std::cout << "f =        " << f << std::endl;
	std::cout << "expected : 12.0508" << std::endl;
	std::cout << "g =        " << g << std::endl;
	std::cout << "expected : 0.453125" << std::endl << std::endl;

	std::cout << "Testing min and max functions :" << std::endl << std::endl;
	std::cout << "max between a and b (const max function called) : " << Fixed::max( a, b ) << std::endl;
	std::cout << "expected :                                        " << b << std::endl;
	std::cout << "max between a and c (normal max function called) : " << Fixed::max( a, c ) << std::endl;
	std::cout << "expected :                                         " << a << std::endl;
	std::cout << "min between a and b (const min function called) : " << Fixed::min( a, b ) << std::endl;
	std::cout << "expected :                                        " << a << std::endl;
	std::cout << "min between a and c (normal max function called) : " << Fixed::min( a, c ) << std::endl;
	std::cout << "expected :                                         " << c << std::endl << std::endl;

	std::cout << "Testing incrementation and decrementation :" << std::endl << std::endl;
	std::cout << "a after incrementation : " << ++a << std::endl;
	std::cout << "expected :               0.00390625" << std::endl;
	std::cout << "a =                      "<< a << std::endl;
	std::cout << "expected :               0.00390625" << std::endl;
	std::cout << "a before incrementation : "<< a++ << std::endl;
	std::cout << "expected :                0.00390625" << std::endl;
	std::cout << "a =                      "<< a << std::endl;
	std::cout << "expected :               0.0078125" << std::endl;
	std::cout << "c after decrementation : " << --c << std::endl;
	std::cout << "expected :               -0.00390625" << std::endl;
	std::cout << "c =                      "<< c << std::endl;
	std::cout << "expected :               -0.00390625" << std::endl;
	std::cout << "c before decrementation : "<< c-- << std::endl;
	std::cout << "expected :                -0.00390625" << std::endl;
	std::cout << "c =                      "<< c << std::endl;
	std::cout << "expected :               -0.0078125" << std::endl << std::endl;

	g = a;
	std::cout << "Testing < > <= >= == != :" << std::endl << std::endl;
	std::cout << "is a lower than b ? : " << (a < b) << std::endl;
	std::cout << "expected :            " << true << std::endl;
	std::cout << "is a greater than b ? : " << (a > b) << std::endl;
	std::cout << "expected :              " << false << std::endl;
	std::cout << "is a lower or equal to g ? : " << (a <= g) << std::endl;
	std::cout << "expected :                   " << true << std::endl;
	std::cout << "is a grater or equal to g ? : " << (a >= g) << std::endl;
	std::cout << "expected :                    " << true << std::endl;
	std::cout << "is a equal to b ? : " << (a == b) << std::endl;
	std::cout << "expected :          " << false << std::endl;
	std::cout << "is a different than b ? : " << (a != b) << std::endl;
	std::cout << "expected :                " << true << std::endl << std::endl;
	return (0);
}