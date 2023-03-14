/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:20 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/14 14:08:07 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Character::Character(void) : _name("Anonymous") _trash_size(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
	return ;
}

Character::Character(std::string& const name) : _name(name) _trash_size(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character constructor by string called" << std::endl;
	return ;
}

Character::Character(const Character& origin)
{
	*this = origin;
	std::cout << "Character constructor by copy called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Character& Character::operator=(const Character& origin)
{
	this->_name = origin._name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = origin._inventory[i];
	// for (int i = 0; !origin._trash[i].empty(); i++)
	// 	this->_trash[i] = origin._trash[i];
	this->_trash_size = 0;
	std::cout << "Character assignation operator called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

std::string& const	Character::getName() const
{
	delete [] this->_inventory;
	delete [] this->_trash;
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;
	while (i < 4 && this->_inventory[i] != NULL)
		i++;
	if (i < 4)
		this->_inventory[i] = m;
	return ;
}

void	Character::unequip(int idx);
{
	AMateria*	newSlot;

	if (idx < 0 || idx > 3)
		return ;
	if (this->_iventory[idx] == NULL)
		return ;
	for (int i = 0; i < this->_trash_size; i++)
		this->_trash[i] = this->_iventory[idx];
	this->_iventory[idx] = NULL;
	this->_trash_size++;
	return ;
}

void	Character::use(int idx, Character& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_iventory[idx] == NULL)
		return ;
	this->_iventory[idx]->use(target);
	return ;
}
