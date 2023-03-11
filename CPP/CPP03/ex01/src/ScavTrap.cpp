/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:27:49 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/11 19:22:07 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_HitPts = 100;
	this->_EnergyPts = 50;
	this->_AttackDmg = 20;
	this->_KeeperMode = false;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& origin) : ClapTrap(origin)
{
	std::cout << "ScavTrap " << this->_Name << " created by copy" << std::endl;
	*this = origin;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_Name = name;
	this->_HitPts = 100;
	this->_EnergyPts = 50;
	this->_AttackDmg = 20;
	this->_KeeperMode = false;
	std::cout << "ScavTrap " << this->_Name << " created by string" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_Name << " destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

ScavTrap& ScavTrap::operator=(const ScavTrap& entry)
{
	if (this == &entry)
		return *this;
	this->_Name = entry._Name;
	this->_HitPts = entry._HitPts;
	this->_EnergyPts = entry._EnergyPts;
	this->_AttackDmg = entry._AttackDmg;
	this->_KeeperMode = entry._KeeperMode;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void	ScavTrap::attack(const std::string& target)
{
	if (this->_HitPts <= 0)
	{
		std::cout << this->_Name << " has no hit points left !" << std::endl;
		return ;
	}
	if (this->_EnergyPts <= 0)
	{
		std::cout << this->_Name << " has no energy points left !" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_Name << " attacks " << target << ", causing ";
	std::cout << this->_AttackDmg << " points of damage !" << std::endl;
	this->_EnergyPts--;
	return ;
}

void	ScavTrap::guardGate()
{
	if (this->_KeeperMode == true)
	{
		std::cout << "ScavTrap " << this->_Name << " already used his guardGate ability." << std::endl;
		return ;
	}
	if (this->_HitPts <= 0)
	{
		std::cout << "ScavTrap " << this->_Name << " has no hit points left !" << std::endl;
		return ;
	}
	if (this->_EnergyPts <= 0)
	{
		std::cout << "ScavTrap " << this->_Name << " has no energy points left !" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_Name << " entered Gate Keeper mode !" << std::endl;
	this->_KeeperMode = true;
	this->_EnergyPts--;
	return ;
}