/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:41:44 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/11 18:01:16 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	RPN rpn;

	if (ac != 2)
	{
		std::cout << "Usage: ./rpn [expression]" << std::endl;
		return (1);
	}
	std::string expr = av[1];
	std::istringstream iss(expr);
	std::string token;

	while (std::getline(iss, token, ' '))
	{
		if (token == "+" && rpn.size() >= 2)
			rpn.add();
		else if (token == "-" && rpn.size() >= 2)
			rpn.sub();
		else if (token == "*" && rpn.size() >= 2)
			rpn.mul();
		else if (token == "/" && rpn.size() >= 2)
			rpn.div();
		else if (token.find_first_not_of("0123456789.") == std::string::npos)
			rpn.push(std::atof(token.c_str()));
		else
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
	}
	rpn.print();
	return (0);
}