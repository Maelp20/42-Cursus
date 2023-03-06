/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:20:51 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 15:55:47 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
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