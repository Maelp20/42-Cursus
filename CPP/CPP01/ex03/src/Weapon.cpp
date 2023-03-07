/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:10:15 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/02 15:57:23 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

void	Weapon::setType(std::string type)
{
    this->_type = type;
    return ;
}

const std::string&	Weapon::getType(void)
{
    return(this->_type) ;
}
