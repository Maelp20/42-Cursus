/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:49:58 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 13:39:15 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	test;

	if (ac != 2)
		return (std::cout << "Wrong number of arguments" << std::endl, 1);
	test.complain(av[1]);
	return (0);
}