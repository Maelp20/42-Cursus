/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:27:49 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 12:41:21 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_HitPts = 100;
	this->_EnergyPts = 50;
	this->_AttackDmg = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap& origin)
{
	*this = origin;
	std::cout << "FragTrap " << this->_Name << " created by copy" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name)
{
	this->_Name = name;
	this->_HitPts = 100;
	this->_EnergyPts = 100;
	this->_AttackDmg = 30;
	std::cout << "FragTrap " << this->_Name << " created by string" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_Name << " destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

FragTrap& FragTrap::operator=(const FragTrap& entry)
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

void	FragTrap::attack(const std::string& target)
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
	std::cout << "FragTrap " << this->_Name << " attacks " << target << ", causing ";
	std::cout << this->_AttackDmg << " points of damage !" << std::endl;
	this->_EnergyPts--;
	return ;
}

void	FragTrap::highFivesGuys()
{
	if (this->_HitPts <= 0)
	{
		std::cout << "FragTrap " << this->_Name << " has no hit points left !" << std::endl;
		return ;
	}
	if (this->_EnergyPts <= 0)
	{
		std::cout << "FragTrap " << this->_Name << " has no energy points left !" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_Name << " : High Five anyone ?" << std::endl;
	this->_EnergyPts--;
	return ;
}