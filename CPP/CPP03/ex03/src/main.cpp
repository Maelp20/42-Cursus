/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:12:44 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 12:58:19 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	Mike("Mike");

	Mike.whoAmI();
	std::cout << "Mike's HitPts : " << Mike.getHitPts() << std::endl ;
	std::cout << "Mike's EnergyPts : " << Mike.getEnergyPts() << std::endl ;
	std::cout << "Mike's AttackDmg : " << Mike.getAttackDmg() << std::endl ;
	for (int i = 0; i < 51; i++)
		Mike.attack("a random person");

	// DiamondTrap	Mike2(Mike);

	// Mike2.whoAmI();
	// std::cout << "Mike2's HitPts : " << Mike2.getHitPts() << std::endl ;
	// std::cout << "Mike2's EnergyPts : " << Mike2.getEnergyPts() << std::endl ;
	// std::cout << "Mike2's AttackDmg : " << Mike2.getAttackDmg() << std::endl ;
	return (0);
}