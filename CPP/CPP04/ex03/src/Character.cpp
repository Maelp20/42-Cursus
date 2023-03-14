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
	std::cout << "Character default constructor called" << std::endl;
	return ;
}

Character::Character(const std::string& name) : _name(name), _trash_size(0)
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
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = origin._inventory[i];
	}
	// for (int i = 0; !origin._trash[i].empty(); i++)
	// 	this->_trash[i] = origin._trash[i];
	this->_trash_size = 0;
	std::cout << "Character assignation operator called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

const std::string&	Character::getName() const
{
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	for (int i = 0; i < 4; i++)
		if (this->_trash[i] != NULL)
			delete this->_trash[i];
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
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx] == NULL)
		return ;
	for (int i = 0; i < this->_trash_size; i++)
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
