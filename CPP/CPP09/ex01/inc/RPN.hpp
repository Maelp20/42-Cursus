/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:41:42 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/11 18:02:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ex01 : stack
//ex02 : vector and deque

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>

class RPN
{
	private:
		std::stack<float> _stack;
	public:
		RPN();
		RPN(RPN const & copy);
		~RPN();

		RPN & operator=(RPN const & copy);

		void	push(float value);
		void	add(void);
		void	sub(void);
		void	mul(void);
		void	div(void);
		void	print(void);
		int		size(void);
} ;

#endif