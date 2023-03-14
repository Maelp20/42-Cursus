/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:29 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/14 14:25:54 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta[4];
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		meta[i]->makeSound();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete meta[i];

	// Animal blubla;
	// Animal *tmp = new Animal();
	return 0;
	
}