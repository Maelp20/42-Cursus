/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:34:32 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/10 16:41:02 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange b;

	if (ac != 2)
	{
		std::cout << "Usage: ./bitcoin [filename]" << std::endl;
		return (1);
	}
	b.readData();
	b.readInput(av[1]);
	return (0);
}