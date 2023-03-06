/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:07:40 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 18:16:51 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) { return; }

Zombie::Zombie(std::string name) { this->name = name; }

Zombie::~Zombie(void) { std::cout << this->name << " Destroyed" << std::endl; }

void	Zombie::announce(void) { std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void	Zombie::give_name(std::string name) { this->name = name; }
