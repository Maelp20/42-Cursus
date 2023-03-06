/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:10:09 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 18:42:53 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	if (name.empty())
	{
		std::cout << "HumanA needs a name !" << std::endl;
		return ;
	}
	this->name = name;
	return ;
}

HumanB::~HumanB(void) { return; }

void	HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; }

void	HumanB::attack(void)
{ 
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
	return ;
}