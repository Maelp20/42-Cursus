/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:12:44 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/10 17:27:58 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	Bobby("Bobby");
	ClapTrap	Johnny("Johnny");
	ClapTrap	Genialo(Johnny);

	Bobby.setDamage(2);
	Johnny.setDamage(10);
	Genialo.setDamage(42);
	Bobby.attack("Johnny");
	Johnny.takeDamage(Bobby.getDamage());
	Johnny.beRepaired(1);
	Johnny.attack("Bobby");
	Bobby.takeDamage(Johnny.getDamage());
	Bobby.beRepaired(2);
	Genialo.attack("Johnny");
	Johnny.takeDamage(Genialo.getDamage());
	Johnny.beRepaired(10);
	return (0);
}