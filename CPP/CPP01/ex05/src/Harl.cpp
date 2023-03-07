/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:49:55 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 12:29:50 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	Harl_init();
	std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl destructor called" << std::endl;
	return ;
}

void	Harl::Harl_init(void)
{
	this->_array[0].level = "DEBUG";
	this->_array[0].f = &Harl::debug;
	this->_array[1].level = "INFO";
	this->_array[1].f = &Harl::info;
	this->_array[2].level = "WARNING";
	this->_array[2].f = &Harl::warning;
	this->_array[3].level = "ERROR";
	this->_array[3].f = &Harl::error;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout <<  "This is unacceptable ! I want to speak to the manager now." << std::endl;
	return ;
}
		
void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
		if (this->_array[i].level == level)
			(this->*_array[i].f)();
	return ;
}