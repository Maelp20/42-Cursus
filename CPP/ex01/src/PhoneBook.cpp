/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:41:51 by mpignet           #+#    #+#             */
/*   Updated: 2023/02/27 17:12:52 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook(void){

	std::cout << "Constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void){
	
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	PhoneBook::add_contact(void){

	std::string	buff;
	
	if (this->nbr_contacts == 8)
		this->nbr_contacts = 1;
	std::cout << "Please enter infos for new contact." << std::endl;
	std::cout << "First name : ";
	std::cin >> buff;
	contacts[nbr_contacts].set_contact(buff, 1);
	std::cout << "Last name : ";
	std::cin >> buff;
	contacts[nbr_contacts].set_contact(buff, 2);
	std::cout << "Nickname : ";
	std::cin >> buff;
	contacts[nbr_contacts].set_contact(buff, 3);
	std::cout << "Phone number : ";
	std::cin >> buff;
	contacts[nbr_contacts].set_contact(buff, 4);
	std::cout << "Darkest Secret : ";
	std::cin >> buff;
	contacts[nbr_contacts].set_contact(buff, 5);
	this->nbr_contacts++;
	return;
}

std::string	prep_buff(std::string str){

	std::string	buff;

	buff = str;
	if (str.size() <= 10)
		buff.resize(10, ' ');
	else
	{
		buff.resize(9);
		buff += '.';
	}
	return (buff);
}

void	PhoneBook::search(void){

	std::string	buff;

	for (int i = 0; i != 8; i++)
	{
		if (this->contacts[i].get_first_name().empty())
			return;
		if (i == 0)
		{
			std::cout << "Index     |";
			std::cout << "First Name|";
			std::cout << "Last Name |";
			std::cout << "Nickname  |";
			std::cout << std::endl;
		}
		std::cout << ""<< (i + 1) <<"         |";
		buff = prep_buff(this->contacts[i].get_first_name());
		std::cout << buff;
		std::cout << "|";
		buff = prep_buff(this->contacts[i].get_last_name());
		std::cout << buff;
		std::cout << "|";
		buff = prep_buff(this->contacts[i].get_nickname());
		std::cout << buff;
		std::cout << "|";
		std::cout << std::endl;
	}
	return;
}
