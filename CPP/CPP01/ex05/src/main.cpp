/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:49:58 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 12:30:25 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	test;

	std::cout << "Debug message test :" << std::endl;
	test.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "Info message test :" << std::endl;
	test.complain("INFO");
	std::cout << std::endl;
	std::cout << "Warning message test :" << std::endl;
	test.complain("WARNING");
	std::cout << std::endl;
	std::cout << "Error message test :" << std::endl;
	test.complain("ERROR");
	std::cout << std::endl;
}