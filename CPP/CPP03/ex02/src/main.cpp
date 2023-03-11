/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:12:44 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/11 19:54:22 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap Clap("Clap");
	FragTrap	Tic("Tic");
	FragTrap	Tac("Tac");
	FragTrap	Toc("Toc");
	FragTrap	Toc2(Toc);
	Tic.attack("Tac");
	Tac.takeDamage(Tic.getDamage());
	Tac.beRepaired(20);
	Tac.highFivesGuys();
	Toc.setDamage(120);
	Toc.attack("Tic");
	Tic.takeDamage(Toc.getDamage());
	Tic.beRepaired(50);
	for(int i = 0; i < 11; i++)
		Clap.attack("Toc2");
	Toc2.takeDamage(0);
	return (0);
}