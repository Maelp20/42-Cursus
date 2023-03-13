/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:29 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 18:02:17 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

/* int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	return 0;
} */

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

	std::cout<< std::endl  << "Now testing that our copies are deep copies :" << std::endl << std::endl;

	Dog Bruno;
	Dog Suzy;

	std::cout << std::endl;
	Suzy.getBrain()->setIdeas("EAT");
	Bruno = Suzy;
	std::cout << std::endl << "Bruno's idea : " << Bruno.getBrain()->getIdeas() << std::endl;
	std::cout << "Suzy's idea : " << Suzy.getBrain()->getIdeas() << std::endl;
	Suzy.getBrain()->setIdeas("PLAY");
	std::cout << std::endl;
	std::cout << "We juste changed Suzy's idea to PLAY : if it's deep copies, Bruno's idea shouldn't be changed" << std::endl << std::endl;
	std::cout << "Bruno's idea : " << Bruno.getBrain()->getIdeas() << std::endl;
	std::cout << "Suzy's idea : " << Suzy.getBrain()->getIdeas() << std::endl;
	std::cout << std::endl;
	return 0;
	
}