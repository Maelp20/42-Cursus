/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:20 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/14 14:08:07 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

MateriaSource::MateriaSource(void) : _name("Anonymous") _trash_size(0)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
	return ;
}

MateriaSource::MateriaSource(std::string& const name) : _name(name) _trash_size(0)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	std::cout << "MateriaSource constructor by string called" << std::endl;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource& origin)
{
	*this = origin;
	std::cout << "MateriaSource constructor by copy called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

MateriaSource& MateriaSource::operator=(const MateriaSource& origin)
{
	this->_name = origin._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
		this->_materias[i] = origin._materias[i];
	}
	std::cout << "MateriaSource assignation operator called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;
	while (i < 4 && this->_materias[i] != NULL)
		i++;
	if (i < 4)
		this->_materias[i] = m;
	return ;	
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	AMateria*	newMateria;
	if (type == "ice")
		newMateria = new Ice();
	if (type == "cure")
		newMateria = new Cure();
	else
		return (0);
	return (newMateria);
}