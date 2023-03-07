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

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;	
	return ;
}

HumanB::~HumanB(void)
{
	return;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	return ;
}

void	HumanB::attack(void)
{ 
	if (this->_weapon != NULL)
	{
		std::cout << this->_name << " attacks with their ";
		std::cout << this->_weapon->getType() << std::endl;
	}
	else
		std::cout << this->_name << " has no weapon !" << std::endl;
	return ;
}