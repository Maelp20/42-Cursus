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
	return ;
}

Character::Character(const std::string& name) : _name(name), _trash_size(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_trash = NULL;
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
	delete [] this->_trash;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Character& Character::operator=(const Character& origin)
{
	if (this != &origin)
	{
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = NULL;
		this->_trash = NULL;
		this->_trash_size = 0;
		this->_name = origin._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			if (origin._inventory[i] != NULL)
				this->_inventory[i] = origin._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

const std::string&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	delete m;
	return ;
}

void	Character::unequip(int idx)
{
	AMateria**	new_trash;

	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx] == NULL)
		return ;
	new_trash = new AMateria *[_trash_size + 1];
	for (int i = 0; i < _trash_size; i++)
		new_trash[i] = this->_trash[i];
	delete []this->_trash;
	this->_trash = new_trash;
	this->_trash[_trash_size] = this->_inventory[idx];
	this->_trash_size++;
	this->_inventory[idx] = NULL;
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
