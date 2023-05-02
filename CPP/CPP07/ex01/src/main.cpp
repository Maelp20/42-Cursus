/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:14:25 by mpignet           #+#    #+#             */
/*   Updated: 2023/04/28 17:28:09 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
	int	arr1[5] = {0, 1, 2, 3, 4};
	char arr2[12] = "Hello World";
	std::string arr3[3] = {"une", "deux", "trois"};

	std::cout << "Trying with an int array :" << std::endl;
	::iter(arr1, 5, display);
	std::cout << "Trying with a char array :" << std::endl;
	::iter(arr2, 12, display);
	std::cout << "Trying with a string array :" << std::endl;
	::iter(arr3, 3, display);
	return 0;
}
