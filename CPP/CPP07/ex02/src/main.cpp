/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:14:25 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/04 14:45:40 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main( void )
{
	std::cout << "creating test, empty array..." << std::endl;
	Array<int>	test;
	std::cout << "creating test3, array of size 5..." << std::endl;
	Array<int>	test2(5);
	std::cout << "creating copy1, copy of test2 with constructor by copy..." << std::endl;
	Array<int> copy1(test2);
	std::cout << "creating copy2, copy of test2 with assignation operator..." << std::endl;
	Array<int> copy2 = test2;
	
	std::cout << "test size = " << test.size() << std::endl;
	std::cout << "test2 size = " << test2.size() << std::endl;
	std::cout << "test2's value at index 3 : " << test2[3] << std::endl;
	std::cout << "copy1 size = " << copy1.size() << std::endl;
	std::cout << "copy1's value at index 3 : " << copy1[3] << std::endl;
	std::cout << "copy2 size = " << copy2.size() << std::endl;
	std::cout << "copy2's value at index 3 : " << copy2[3] << std::endl;
	std::cout << "changing test2's value at index 3 to 42" << std::endl;
	test2[3] = 42;
	std::cout << "test2's value at index 3 : " << test2[3] << std::endl;
	std::cout << "copy1's value at index 3 : " << copy1[3] << std::endl;
	std::cout << "copy2's value at index 3 : " << copy2[3] << std::endl;
	std::cout << "testing our exception :" << std::endl;
	try {
		std::cout << test[55] << std::endl;
		std::cout << "whuut ?" << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
