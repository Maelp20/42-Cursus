/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:10:09 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/02 16:08:44 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

void	HumanB::attack(void) { 
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; }

HumanB::HumanB(std::string name) { this->name = name; }

HumanB::~HumanB(void) { return; }