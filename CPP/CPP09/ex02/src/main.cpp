/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:07:35 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/18 18:53:00 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe p;

	if (ac < 2)
	{
		std::cout << "Usage: ./pmergeme [integers]" << std::endl;
		return (1);
	}
	p.fill_vec(av);
	p.fill_deq(av);
	p.sort_vec(0, );
	p.sort_deq(0, p._deq.size() - 1);
	p.display_vec();
	p.display_deq();
	return (0);
}