/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:59:18 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/04 19:03:56 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> test;
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
	return (0);
}