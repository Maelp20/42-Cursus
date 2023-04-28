/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:03:19 by mpignet           #+#    #+#             */
/*   Updated: 2023/04/28 16:59:18 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
	std::srand((unsigned) time(NULL));
	int random = rand()	% 3;
	if (random == 0)
	{
		std::cout << "Create A Class" << std::endl;
		return (new A);
	}
	else if (random == 1)
	{
		std::cout << "Create B Class" << std::endl;
		return (new B);
	}
	std::cout << "Create C Class" << std::endl;
	return (new C);
}

void identify(Base* p)
{
	try {
		A	&A_obj = dynamic_cast<A &>(*p);
		(void)A_obj;
		std::cout << "the object is of A type" << std::endl;
	}
	catch (std::exception const &e) {
		try {			
			B	&B_obj = dynamic_cast<B &>(*p);
			(void)B_obj;
			std::cout << "the object is of B type" << std::endl;
		}
		catch (std::exception const &e) {
			try {				
				C	&C_obj = dynamic_cast<C &>(*p);
				(void)C_obj;
				std::cout << "the object is of C type" << std::endl;
			}
			catch (std::exception const &e){
				std::cout << "the object is neither A, B nor C" << std::endl;
			}
		}
	}
	return ;
}

void identify(Base& p)
{
	try {
		A	&A_obj = dynamic_cast<A &>(p);
		(void)A_obj;
		std::cout << "the object is of A type" << std::endl;
	}
	catch (std::exception const &e) {
		try {			
			B	&B_obj = dynamic_cast<B &>(p);
			(void)B_obj;
			std::cout << "the object is of B type" << std::endl;
		}
		catch (std::exception const &e) {
			try {				
				C	&C_obj = dynamic_cast<C &>(p);
				(void)C_obj;
				std::cout << "the object is of C type" << std::endl;
			}
			catch (std::exception const &e){
				std::cout << "the object is neither A, B nor C" << std::endl;
			}
		}
	}
	return ;	
}

int	main(void)
{
	Base *test;
	D	*testD = NULL;
	
	test = generate();
	identify(test);
	identify(*test);
	identify(*testD);
	delete test;
	return (0);
}