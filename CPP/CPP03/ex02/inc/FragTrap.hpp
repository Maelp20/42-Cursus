/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:07:36 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/11 19:50:18 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const FragTrap&);
	FragTrap& operator=(const FragTrap&);
	FragTrap(std::string name);
	~FragTrap(void);

	void	attack(const std::string& target);
	void	highFivesGuys(void);
private:
	bool	_KeeperMode;
} ;

#endif