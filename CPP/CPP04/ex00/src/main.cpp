/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:29 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 15:26:24 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

/* int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	return 0;
} */

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " : " << std::endl;
	meta->makeSound();
	std::cout << j->getType() << " : " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " : " << std::endl;
	i->makeSound();

	std::cout << std::endl << "Now testing WrongAnimal and WrongCat" << std::endl << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();

	std::cout << meta2->getType() << " : " << std::endl;
	meta2->makeSound();
	std::cout << i2->getType() << " : " << std::endl;
	i2->makeSound();
	delete meta;
	delete j;
	delete i;
	delete meta2;
	delete i2;
	return 0;
}