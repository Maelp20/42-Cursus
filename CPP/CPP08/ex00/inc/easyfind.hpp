/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:58:19 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/04 19:03:37 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>

template <typename T>
int	easyfind(T & cont, int n)
{
	if (cont.empty())
		throw std::invalid_argument("container is empty");
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it == cont.end())
		throw std::invalid_argument("Value not found in container");
	return (*it);
}

# endif