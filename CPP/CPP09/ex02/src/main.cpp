/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:07:35 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/22 15:53:20 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <ctime>

int	check_input( char ** input ) {
	unsigned int i = 0;

	while (input[++i]) {
		unsigned j = -1;
		while (input[i][++j]) {
			if (input[i][j] >= '0' && input[i][j] <= '9') {
				continue;
			}
			else {
				return (1);
			}
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
    PmergeMe p;
	if (ac < 2 || check_input(av)) {
		std::cout << "Usage: ./pmergeme [positive integers]" << std::endl;
		return (1);
	}

	p.fill_vec(av);
	p.fill_deq(av);
	std::cout << "Before : " ;
	p.display_vec();
	// std::cout << "Before (deq): " ;
	// p.display_deq();

	struct timespec tmp;
	clock_gettime(CLOCK_REALTIME, &tmp);
	long begin = tmp.tv_nsec;
	p.sort_vec(0, p.size_vec() - 1);
	clock_gettime(CLOCK_REALTIME, &tmp);
	long end = tmp.tv_nsec;
	std::cout << "After : " ;
	p.display_vec();
	std::cout << "Time to process a range of " << p.size_vec() << " elements with std::vector : " << end - begin << " ns" << std::endl;
	clock_gettime(CLOCK_REALTIME, &tmp);
	begin = tmp.tv_nsec;
	p.sort_deq(0, p.size_deq() - 1);
	clock_gettime(CLOCK_REALTIME, &tmp);
	end = tmp.tv_nsec;
	// std::cout << "After (deq): " ;
	// p.display_deq();
	std::cout << "Time to process a range of " << p.size_deq() << " elements with std::deque : " << end - begin << " ns" << std::endl;
	return (0);
}