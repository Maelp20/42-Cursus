/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:58:19 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/04 17:45:52 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

class NotFoundException : public std::exception {
	public:
		virtual const char * what() const throw();
} ;

const char *NotFoundException::what(void) const throw() {
	return ("element not found.");
}

template <typename T>
void	easyfind(T cont, int n)
{
	int i = -1;
	while (cont[++i])
	{
		if (cont[i] == n)
		{
			std::cout << "element found !" << std::endl;
			return ;
		}
	}
	throw NotFoundException();
}


# endif