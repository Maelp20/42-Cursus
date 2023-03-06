/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:09:57 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 18:44:40 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) {

	if (name.empty() || weapon.getType().empty())
	{
		std::cout << "HumanA needs a name and a weapon !" << std::endl;
		return ;
	}
	this->name = name;
	this->weapon = &weapon;
	return ;
}

HumanA::~HumanA(void) { return; }

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
	return ;
}
