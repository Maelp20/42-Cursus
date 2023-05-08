/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:33:08 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/08 15:43:44 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "\x1B[33m" << "First test: everything working normally :" << "\033[0m\t\t" << std::endl << std::endl;
	try {		
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1B[33m" << "Second test: only the same number in vector :" << "\033[0m\t\t" << std::endl << std::endl;
	try {		
		Span sp(5);
		sp.addNumber(2);
		sp.addNumber(2);
		sp.addNumber(2);
		sp.addNumber(2);
		sp.addNumber(2);
		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1B[33m" << "Third test: we try to add too much numbers :" << "\033[0m\t\t" << std::endl << std::endl;
	try {		
		Span sp(3);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1B[33m" << "Fourth test: only one number in vector :" << "\033[0m\t\t" << std::endl << std::endl;
	try {		
		Span sp(5);
		sp.addNumber(6);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1B[33m" << "Fifth test: vector is empty :" << "\033[0m\t\t" << std::endl << std::endl;
	try {		
		Span sp(5);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1B[33m" << "Sixth test: adding lots of numbers via another vector:" << "\033[0m\t\t" << std::endl << std::endl;
	try {		
		Span sp(25000);
		std::vector<int> tmp;
		int random;
		std::srand((unsigned) time(NULL));
		for (int i = 1; i != 25000; i++) {
			random = rand();
			tmp.push_back(random);
		}
		sp.addNumber(tmp);
		std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}