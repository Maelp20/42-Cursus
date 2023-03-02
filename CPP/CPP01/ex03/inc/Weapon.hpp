/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:09:44 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/02 16:12:05 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon {

public:

	Weapon(std::string type);
	Weapon(void);
	~Weapon(void);

	const std::string&	getType(void);
	void				setType(std::string type);

private:

	std::string	type;

} ;

#endif