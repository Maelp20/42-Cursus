/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:09:57 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/02 16:08:36 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

void	HumanA::attack(void) {

	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
	return ;
}

HumanA::HumanA(std::string name, Weapon& weapon) {

	this->name = name;
	this->weapon = &weapon;
	return ;
}

HumanA::~HumanA(void) { return; }