/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:23 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 16:09:01 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain& origin)
{
	*this = origin;
	std::cout << "Brain constructor by copy called" << std::endl;
	return ;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

/*--------------------------------OPERATORS-----------------------------------*/

Brain& Brain::operator=(const Brain& origin)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = origin.ideas[i];
	std::cout << "Brain assignation called" << std::endl;
	return (*this);
}

/*------------------------------MEMBER FUNCTIONS------------------------------*/

void	Brain::setIdeas(const std::string& entry)
{
	this->ideas[0] = entry;
	return ;
}

std::string	Brain::getIdeas()
{
	return (this->ideas[0]);
}