/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:33:10 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/08 15:42:19 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	return ;
}

Span::Span(unsigned int N)
{
	_max_size = N;
	return ;
}

Span::Span(Span const & src)
{
	_nbrs = src._nbrs;
	_max_size = src.get_max_size();
	return ;
}

Span::~Span(void)
{
	return ;
}

Span & Span::operator=(Span const & rhs)
{
	_nbrs = rhs._nbrs;
	_max_size = rhs.get_max_size();
	return (*this);
}


unsigned int const &	Span::get_max_size(void) const
{
	return (_max_size);
}

void	Span::addNumber(int const & n)
{
	if (_nbrs.size() == _max_size)
		throw std::range_error("Vector is already at max size");
	_nbrs.push_back(n);
	return;
}

void	Span::addNumber(std::vector<int> & vec)
{
	if ((_nbrs.size() + vec.size()) >= _max_size)
		throw std::range_error("Too many numbers to add, will cap max size");
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		_nbrs.push_back(*it);
	}
	return;
}

int	Span::shortestSpan(void)
{
	std::vector<int>	tmp = _nbrs;
	int 				diff;
	int 				min_diff = 2147483647;

	if (tmp.empty() || tmp.size() < 2)
		throw std::range_error("Vector is empty or there's only 1 number in it");
	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator it = tmp.begin(); it != (tmp.end() - 1); it++) {
		diff = abs(*it - *(it + 1));
		if (diff < min_diff)
			min_diff = diff;
	}
	return(min_diff);
}

int	Span::longestSpan(void)
{
	std::vector<int>	tmp = _nbrs;

	if (tmp.empty() || tmp.size() < 2)
		throw std::range_error("Vector is empty or there's only 1 number in it");
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}
