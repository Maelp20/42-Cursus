/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:07:36 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 12:12:44 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(const ScavTrap&);
	ScavTrap& operator=(const ScavTrap&);
	ScavTrap(std::string name);
	~ScavTrap(void);

	void	attack(const std::string& target);
	void	guardGate();
protected:
	bool	_KeeperMode;
} ;

#endif