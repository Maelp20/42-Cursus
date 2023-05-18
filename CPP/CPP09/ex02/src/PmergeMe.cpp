/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:07:38 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/18 18:49:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return;
}

PmergeMe::PmergeMe(const PmergeMe & copy)
{
	*this = copy;
	return;
}

PmergeMe::~PmergeMe()
{
	return;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & rhs)
{
	(void)rhs;
	return (*this);
}

void	PmergeMe::fill_vec(char **input)
{
	int i = 0;
	while (input[++i])
		_vec.push_back(atoi(input[i]));
	return ;
}

void	PmergeMe::fill_deq(char **input)
{
	int i = 0;
	while (input[++i])
		_deq.push_back(atoi(input[i]));
	return ;
}

void PmergeMe::display_vec(void)
{
	std::vector<int>::iterator it = _vec.begin();
	while (it != _vec.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::display_deq(void)
{
	std::deque<int>::iterator it = _deq.begin();
	while (it != _deq.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	PmergeMe::insertion_vec(int start, int end)
{
	int i = start;
	int j;
	int tmp;

	while (i <= end)
	{
		j = i;
		while (j > start && _vec[j - 1] > _vec[j])
		{
			tmp = _vec[j];
			_vec[j] = _vec[j - 1];
			_vec[j - 1] = tmp;
			j--;
		}
		i++;
	}
}

void	PmergeMe::merge_vec(int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = 0;
	int tmp[end - start + 1];

	while (i <= mid && j <= end)
	{
		if (_vec[i] < _vec[j])
			tmp[k++] = _vec[i++];
		else
			tmp[k++] = _vec[j++];
	}
	while (i <= mid)
		tmp[k++] = _vec[i++];
	while (j <= end)
		tmp[k++] = _vec[j++];
	i = start;
	k = 0;
	while (i <= end)
		_vec[i++] = tmp[k++];
}

void	PmergeMe::sort_vec(int start, int end)
{
	if (end - start > 5) {
		int mid = (start + end) / 2;
		sort_vec(start, mid);
		sort_vec(mid + 1, end);
		merge_vec(start, mid, end);
	}
	else
		insertion_vec(start, end);
}

