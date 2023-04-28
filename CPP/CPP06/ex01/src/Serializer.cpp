/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:47:32 by mpignet           #+#    #+#             */
/*   Updated: 2023/04/28 14:58:00 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Serializer::Serializer(void)
{
	std::cout << "Serializer created" << std::endl;
	return;
}

Serializer::Serializer(const Serializer& src)
{
	std::cout << "Serializer created by copy" << std::endl;
	*this = src;
	return;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Serializer::~Serializer(void)
{
	std::cout << "Serializer destroyed" << std::endl;
	return;
}

/*--------------------------------OPERATORS-----------------------------------*/

Serializer&	Serializer::operator=(const Serializer& src)
{
	(void)src;
	std::cout << "Serializer assignment operator called" << std::endl;
	return(*this);
}


/*--------------------------------ACCESSORS-----------------------------------*/


/*------------------------------MEMBER FUNCTIONS------------------------------*/

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}




/*--------------------------------EXCEPTIONS-----------------------------------*/


