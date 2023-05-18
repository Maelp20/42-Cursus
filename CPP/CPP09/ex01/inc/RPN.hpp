/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:41:42 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/18 15:08:17 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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