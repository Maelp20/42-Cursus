/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:41:51 by mpignet           #+#    #+#             */
/*   Updated: 2023/02/28 14:48:13 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
		this->nbr_contacts = 0;
	std::cout << "Please enter infos for new contact :" << std::endl;
	std::cout << "First name : ";
	std::getline(std::cin, buff);
	if (std::cin.fail())
		return;
	contacts[nbr_contacts].set_contact(buff, 1);
	std::cout << "Last name : ";
	std::getline(std::cin, buff);
	if (std::cin.fail())
		return;
	contacts[nbr_contacts].set_contact(buff, 2);
	std::cout << "Nickname : ";
	std::getline(std::cin, buff);
	if (std::cin.fail())
		return;
	contacts[nbr_contacts].set_contact(buff, 3);
	std::cout << "Phone number : ";
	std::getline(std::cin, buff);
	if (std::cin.fail())
		return;
	contacts[nbr_contacts].set_contact(buff, 4);
	std::cout << "Darkest Secret : ";
	std::getline(std::cin, buff);
	if (std::cin.fail())
		return;
	contacts[nbr_contacts].set_contact(buff, 5);
	this->nbr_contacts++;
	return;
}

std::string	prep_string(std::string str){

	std::string	buff;

	buff = str;
	if (str.size() < 10)
		buff.resize(10, ' ');
	else
	{
		buff.resize(9);
		buff += '.';
	}
	return (buff);
}

void	PhoneBook::search(void){

	if (this->nbr_contacts == 0)
	{
		std::cout << "Phonebook is empty, use ADD to add a contact !" << std::endl;
		return ;
	}
	for (int i = 0; i != 8; i++)
	{
		if (this->contacts[i].get_first_name().empty())
			break ;
		if (i == 0)
		{
			std::cout << "Index     |" << "First Name|";
			std::cout << "Last Name |" << "Nickname  |" << std::endl;
		}
		std::cout << i <<"         |";
		std::cout << prep_string(this->contacts[i].get_first_name()) << "|";
		std::cout << prep_string(this->contacts[i].get_last_name()) << "|";
		std::cout << prep_string(this->contacts[i].get_nickname()) << "|" << std::endl;
	}
	std::cout << "Please enter a contact's index you want to check :" << std::endl;
	int	index;
	std::cin >> index;
	if (std::cin.fail())
	{
		if (std::cin.eof())
			return ;
		std::cout << "Wrong index" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (index < 0 || index > (this->nbr_contacts - 1))
	{
		std::cout << "Wrong index" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Here's the requested contact's infos :" << std::endl;
	std::cout << "First name : " << this->contacts[index].get_first_name() << std::endl;
	std::cout << "Last name : " << this->contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname : " << this->contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number : " << this->contacts[index].get_phone_nbr() << std::endl;
	std::cout << "Darkest secret : " << this->contacts[index].get_secret() << std::endl;
	return ;
}
