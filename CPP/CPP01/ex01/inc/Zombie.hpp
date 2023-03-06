/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:06:37 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 18:04:25 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void	announce(void);
	void	give_name(std::string name);
private:
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif