/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:59:18 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/05 16:15:03 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	test;
	std::deque<int>		test2;
	test.push_back(42);
	test.push_back(43);
	test.push_back(44);
	test.push_back(45);
	int found;
	try {
		found = easyfind(test, 42);
		std::cout << "Value found !" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	test2.push_back(42);
	test2.push_back(43);
	test2.push_back(44);
	test2.push_back(45);
	try {
		found = easyfind(test2, 48);
		std::cout << "Value found !" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}