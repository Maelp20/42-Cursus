/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:09:41 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 18:17:23 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);
	~HumanB(void);

	void	attack(void);
	void	setWeapon(Weapon& weapon);
private:
	std::string	_name;
	Weapon*		_weapon;
} ;

#endif