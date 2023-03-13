/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:27:49 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/11 19:22:07 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

DiamondTrap::DiamondTrap(void)
{
	this->_HitPts = this->FragTrap::_HitPts;
	this->_EnergyPts = this->ScavTrap::_EnergyPts;
	this->_AttackDmg = this->FragTrap::_AttackDmg;
	this->_KeeperMode = this->ScavTrap::_KeeperMode;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& origin)
{
	*this = origin;
	std::cout << "DiamondTrap " << this->_Name << " created by copy" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_Name = name;
	this->ClapTrap::_Name = name + "_clap_name";
	this->_HitPts = this->FragTrap::_HitPts;
	this->_EnergyPts = this->ScavTrap::_EnergyPts;
	this->_AttackDmg = this->FragTrap::_AttackDmg;
	this->_KeeperMode = this->ScavTrap::_KeeperMode;
	std::cout << "DiamondTrap " << this->_Name << " created by string" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_Name << " destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& entry)
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

int	DiamondTrap::getHitPts(void)
{
	return (this->_HitPts);
}

int	DiamondTrap::getEnergyPts()
{
	return (this->_EnergyPts);
}

int	DiamondTrap::getAttackDmg()
{
	return (this->_AttackDmg);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap : My name is " << this->_Name << std::endl;
	std::cout << "ClapTrap origin : My name is " << this->ClapTrap::_Name << std::endl;
	return ;
}