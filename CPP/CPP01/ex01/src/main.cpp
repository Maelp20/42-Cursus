/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:07:12 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 18:09:41 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	nb = 5;
	Zombie*	horde = zombieHorde(nb, "John");
	if (horde == NULL)
		return (1);
	for (int i = 0; i < nb; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}