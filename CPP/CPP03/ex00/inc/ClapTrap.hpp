/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:07:36 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/10 17:26:04 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

public:
	ClapTrap(void);
	ClapTrap(const ClapTrap&);
	ClapTrap& operator=(const ClapTrap&);
	ClapTrap(std::string name);
	~ClapTrap(void);

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			setDamage(unsigned int amount);
	unsigned int	getDamage(void);
private:
	std::string _Name;
	int			_HitPts;
	int			_EnergyPts;
	int			_AttackDmg;	
} ;

#endif