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

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource& origin)
{
	*this = origin;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

MateriaSource& MateriaSource::operator=(const MateriaSource& origin)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
		this->_materias[i] = origin._materias[i];
	}
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			return ;
		}
	}
	delete m;
	return ;	
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	i = -1;

	while (++i < 4)
		if (this->_materias[i] && type == this->_materias[i]->getType())
			return (this->_materias[i]->clone());
	return (NULL);
}