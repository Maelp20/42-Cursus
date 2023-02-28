/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:07:40 by mpignet           #+#    #+#             */
/*   Updated: 2023/02/28 19:17:30 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void) { std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

Zombie::Zombie(std::string name) { this->name = name; }

Zombie::~Zombie(void) { std::cout << this->name << " Destroyed" << std::endl; }