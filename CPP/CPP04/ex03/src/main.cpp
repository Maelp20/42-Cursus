/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:29 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/20 16:04:25 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "----------Subject tests----------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << "----------Character creations tests----------" << std::endl;

	Character	fred = Character("fred");

	fred.equip(new Ice());

	Character	copy = fred;
	Character	target = Character("target");
	
	fred.use(0, target);
	fred.unequip(0);
	std::cout << "We unequip fred's Ice : copy should still be able to use it's own Ice" << std::endl;
	fred.use(0, target);
	copy.use(0, fred);

	std::cout << "Now if we unequip copy, nothing should happen :" << std::endl;
	copy.unequip(0);
	copy.use(0, fred);

	std::cout << "----------equip, unequip & use tests----------" << std::endl;

	Character mage = Character("mage");
	Character healer = Character("healer");

	mage.equip(new Ice());
	mage.equip(new Ice());
	mage.equip(new Ice());
	mage.equip(new Ice());
	mage.equip(new Ice());
	mage.equip(new Ice());
	mage.equip(new Ice());
	mage.use(0, fred);
	mage.use(1, fred);
	mage.use(2, fred);
	mage.use(3, fred);
	mage.use(42, fred);
	mage.unequip(0);
	mage.unequip(1);
	mage.unequip(2);
	mage.unequip(3);
	mage.unequip(4);
	mage.unequip(42);
	mage.use(3, fred);

	healer.equip(new Cure());
	healer.use(0, fred);
	healer.unequip(0);
	healer.equip(new Cure());
	healer.unequip(0);
	healer.equip(new Cure());
	healer.unequip(0);
	healer.equip(new Cure());
	healer.unequip(0);
	healer.equip(new Cure());
	healer.unequip(0);
	healer.equip(new Cure());
	healer.unequip(0);
	healer.use(0, fred);

	std::cout << "----------MateriaSource tests----------" << std::endl;

	IMateriaSource* newsrc = new MateriaSource();
	ICharacter* John = new Character("John");
	AMateria* tmp2;

	newsrc->learnMateria(new Ice());
	newsrc->learnMateria(new Cure());
	newsrc->learnMateria(new Ice());
	newsrc->learnMateria(new Cure());
	newsrc->learnMateria(new Ice());
	newsrc->learnMateria(new Cure());
	newsrc->learnMateria(new Ice());
	newsrc->learnMateria(new Cure());

	tmp2 = newsrc->createMateria("ice");
	John->equip(tmp2);
	tmp2 = newsrc->createMateria("cure");
	John->equip(tmp2);
	tmp2 = newsrc->createMateria("ice");
	John->equip(tmp2);
	tmp2 = newsrc->createMateria("ice");
	John->equip(tmp2);
	tmp2 = newsrc->createMateria("cure");
	John->equip(tmp2);
	tmp2 = newsrc->createMateria("cure");
	John->equip(tmp2);

	ICharacter* Jack = new Character("Jack");
	John->use(0, *Jack);
	John->use(1, *Jack);
	John->use(2, *Jack);
	John->use(3, *Jack);
	John->use(4, *Jack);
	John->use(5, *Jack);
	John->use(-1, *Jack);
	John->use(8486132, *Jack);

	delete newsrc;
	delete John;
	delete Jack;
	return 0;
}