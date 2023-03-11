/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:07:36 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/11 19:21:38 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(const ScavTrap&);
	ScavTrap& operator=(const ScavTrap&);
	ScavTrap(std::string name);
	~ScavTrap(void);

	void	attack(const std::string& target);
	void	guardGate();
private:
	bool	_KeeperMode;
} ;

#endif