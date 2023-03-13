/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:07:36 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/11 19:21:38 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, FragTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap&);
	DiamondTrap& operator=(const DiamondTrap&);
	DiamondTrap(std::string name);
	~DiamondTrap(void);

	int	getHitPts();
	int	getEnergyPts();
	int	getAttackDmg();
	using ScavTrap::attack;
	void	whoAmI();
private:
	std::string _Name;
} ;

#endif