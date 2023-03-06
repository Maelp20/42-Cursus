/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:49:53 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 12:22:02 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl {
typedef	struct s_arr {
	std::string	level;
	void(Harl::*f)(void);
} 		t_arr;
public :
	Harl(void);
	~Harl(void);

	void	Harl_init(void);
	void	complain(std::string level);
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	t_arr	array[4];
} ;