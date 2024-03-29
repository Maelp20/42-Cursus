/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:06:37 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 18:15:56 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
public:
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);
private:
	std::string _name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif