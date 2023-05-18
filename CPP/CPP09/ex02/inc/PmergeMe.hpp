/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:07:33 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/18 18:49:40 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>

//our program must use a merge-insert sort algorithm to sort a positive integer sequence
// we will use 2 containers : vector and deque

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe & operator=(const PmergeMe & rhs);
		~PmergeMe();

	void	fill_vec(char **input);
	void	fill_deq(char **input);
	void	sort_vec(int start, int end);
	void	sort_deq(int start, int end);
	void	insertion_vec(int start, int end);
	void	insertion_deq(int start, int end);
	void	merge_vec(int start, int mid, int end);
	void	merge_deq(int start, int mid, int end);
	void	display_vec();
	void	display_deq();
} ;


# endif