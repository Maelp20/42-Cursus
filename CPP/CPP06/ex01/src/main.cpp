/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:51:27 by mpignet           #+#    #+#             */
/*   Updated: 2023/04/28 15:00:39 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	test;
	Data*	data_ptr;

	test.x = 1;
	test.y = 2;
	std::cout << "test.x = " << test.x << std::endl;
	std::cout << "test.y = " << test.y << std::endl;
	data_ptr = Serializer::deserialize(Serializer::serialize(&test));
	std::cout << "data_ptr->x = " << data_ptr->x << std::endl;
	std::cout << "data_ptr->y = " << data_ptr->y << std::endl;
	return (0);
}