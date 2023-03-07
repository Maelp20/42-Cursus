/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:25:18 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 18:06:55 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name ) {
	Zombie*	horde = NULL;

	if (N <= 0)
		return (std::cout << "Need at list 1 zombie !" << std::endl, horde);
	if (N > 500000)
		return (std::cout << "Wow calm down, too many zombies !" << std::endl, horde);
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].give_name(name);
	return (horde);
}