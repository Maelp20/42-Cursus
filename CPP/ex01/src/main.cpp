/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:25:56 by mpignet           #+#    #+#             */
/*   Updated: 2023/02/27 15:46:00 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int	main(void)
{
	std::string buff;
	PhoneBook my_rolodex;

	while (1)
	{		
		std::cout << "Entry: ";
		std::cin >> buff;
		if (buff == "ADD")
			my_rolodex.add_contact();
		else if (buff == "SEARCH")
			my_rolodex.search();
		else if (buff == "EXIT")
			break ;
		else
			continue;
	}
	return (0);
}