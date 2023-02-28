/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:25:56 by mpignet           #+#    #+#             */
/*   Updated: 2023/02/28 14:43:37 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>

int	main(void)
{
	PhoneBook	my_rolodex;
	std::string	buff;

	while (1)
	{
		std::cout << "Entry: ";
		std::getline(std::cin, buff);
		if (std::cin.fail())
			return (1);
		if (buff == "ADD")
			my_rolodex.add_contact();
		else if (buff == "SEARCH")
			my_rolodex.search();
		else if (buff == "EXIT")
			break ;
	}
	return (0);
}