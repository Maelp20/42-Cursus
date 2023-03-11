/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:12:44 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/11 19:29:03 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap Clap("Clap");
	ScavTrap	Tic("Tic");
	ScavTrap	Tac("Tac");
	ScavTrap	Toc("Toc");
	ScavTrap	Toc2(Toc);
	Tic.attack("Tac");
	Tac.takeDamage(Tic.getDamage());
	Tac.beRepaired(20);
	Tac.guardGate();
	Tac.guardGate();
	Toc.setDamage(120);
	Toc.attack("Tic");
	Tic.takeDamage(Toc.getDamage());
	Tic.beRepaired(50);
	for(int i = 0; i < 11; i++)
		Clap.attack("Toc2");
	Toc2.takeDamage(0);
	return (0);
}