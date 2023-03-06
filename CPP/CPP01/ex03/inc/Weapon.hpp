/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:09:44 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 18:27:58 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon {
public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);

	const std::string&	getType(void);
	void				setType(std::string type);
private:
	std::string	type;
} ;

#endif