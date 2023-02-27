/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:25:56 by mpignet           #+#    #+#             */
/*   Updated: 2023/02/27 19:58:42 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>

int	main(void)
{
	PhoneBook my_rolodex;

	while (1)
	{	
		std::string buff;	
		std::cout << "Entry: ";
		std::cin >> buff;
		if (buff == "ADD")
			my_rolodex.add_contact();
		else if (buff == "SEARCH")
			my_rolodex.search();
		else if (buff == "EXIT")
			break ;
	}
	return (0);
}