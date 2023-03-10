/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:27:49 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/10 17:28:27 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

ClapTrap::ClapTrap(void) : _HitPts(10), _EnergyPts(10), _AttackDmg(0)
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& origin)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = origin;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPts(10), _EnergyPts(10), _AttackDmg(0)
{
	std::cout << "Named Constructor called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

ClapTrap& ClapTrap::operator=(const ClapTrap& entry)
{
	if (this == &entry)
		return *this;
	this->_Name = entry._Name;
	this->_HitPts = entry._HitPts;
	this->_EnergyPts = entry._EnergyPts;
	this->_AttackDmg = entry._AttackDmg;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

unsigned int	ClapTrap::getDamage(void)
{
	return (this->_AttackDmg);
}

void	ClapTrap::setDamage(unsigned int amount)
{
	this->_AttackDmg = amount;
	std::cout << this->_Name << " now has " << this->_AttackDmg << " attack damage"<< std::endl;
	return ;
}

void	ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing ";
	std::cout << this->_AttackDmg << " points of damage !" << std::endl;
	this->_EnergyPts--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPts <= 0)
	{
		std::cout << this->_Name << " has no hit points left !" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_Name << " takes " << amount;
	std::cout << " points of damage !" << std::endl;
	this->_HitPts -= amount;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
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
	std::cout << "ClapTrap " << this->_Name << " repairs for " << amount;
	std::cout << " hitpoints !" << std::endl;
	this->_EnergyPts--;
	this->_HitPts += amount;
	return ;
}
