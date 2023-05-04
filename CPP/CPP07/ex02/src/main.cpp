/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:14:25 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/04 18:24:08 by mpignet          ###   ########.fr       */
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

	try {
		std::cout << "test size = " << test.size() << std::endl;
		std::cout << "test2 size = " << test2.size() << std::endl;
		std::cout << "test2's value at index 3 : " << test2[3] << std::endl;
		std::cout << "copy1 size = " << copy1.size() << std::endl;
		std::cout << "copy1's value at index 3 : " << copy1[3] << std::endl;
		std::cout << "copy2 size = " << copy2.size() << std::endl;
		std::cout << "copy2's value at index 3 : " << copy2[3] << std::endl << std::endl;
		std::cout << "changing test2's value at index 3 to 42" << std::endl;
		test2[3] = 42;
		std::cout << "test2's value at index 3 : " << test2[3] << std::endl;
		std::cout << "copy1's value at index 3 : " << copy1[3] << std::endl;
		std::cout << "copy2's value at index 3 : " << copy2[3] << std::endl << std::endl;
		std::cout << "testing our exception :" << std::endl;
		std::cout << test[55] << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	const Array<int> test_const(6);
	
	std::cout << "we check that our operator[] works with a type const Array : test_const[1] = ";
	std::cout << test_const[1] << std::endl;
	return 0;
}
