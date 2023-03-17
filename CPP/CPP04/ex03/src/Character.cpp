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

Character::Character(void) : _name("Anonymous"), _trash_size(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_trash = NULL;
	this->_trash_size = 0;
	return ;
}

Character::Character(const std::string& name) : _name(name), _trash_size(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_trash = NULL;
	this->_trash_size = 0;
	return ;
}

Character::Character(const Character& origin)
{
	*this = origin;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	for (int i = 0; i < this->_trash_size; i++)
		if (this->_trash[i] != NULL)
			delete this->_trash[i];
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Character& Character::operator=(const Character& origin)
{
	this->_name = origin._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = origin._inventory[i];
	}
	this->_trash_size = 0;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

const std::string&	Character::getName() const
{
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

void	Character::unequip(int idx)
{
	int	i = 0;
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx] == NULL)
		return ;
	while(i < this->_trash_size)
		i++;
	this->_trash[i] = this->_inventory[idx];
	this->_inventory[idx] = NULL;
	this->_trash_size++;
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
	return ;
}
