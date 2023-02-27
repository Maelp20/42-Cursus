/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:39:04 by mpignet           #+#    #+#             */
/*   Updated: 2023/02/27 19:13:53 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){
	
	std::cout << "Constructor called" << std::endl;
	return ;
}

Contact::~Contact(void){
	
	std::cout << "Destructor called" << std::endl;
	return ;
}

std::string	Contact::get_first_name(void){
	return (this->first_name);
}

std::string	Contact::get_last_name(void){
	return (this->last_name);
}

std::string	Contact::get_nickname(void){
	return (this->nickname);
}

std::string	Contact::get_phone_nbr(void){
	return (this->phone_nbr);
}

std::string	Contact::get_secret(void){
	return (this->secret);
}

void	Contact::set_contact(std::string input, int elem){
	if (elem == 1)
		this->first_name = input;
	else if (elem == 2)
		this->last_name = input;
	else if (elem == 3)
		this->nickname = input;
	else if (elem == 4)
		this->phone_nbr = input;
	else if (elem == 5)
		this->secret = input;
}