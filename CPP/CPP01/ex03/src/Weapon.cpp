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

void	Weapon::setType(std::string type) { this->type = type; }

const std::string&	Weapon::getType(void) { return(this->type); }

Weapon::Weapon(std::string type) { this->setType(type); }

Weapon::Weapon(void) { return ; }

Weapon::~Weapon(void) { return ; }