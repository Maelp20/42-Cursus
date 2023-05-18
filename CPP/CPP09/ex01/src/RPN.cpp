/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:41:47 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/18 15:04:41 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	return;
}

RPN::RPN(RPN const & copy)
{
	*this = copy;
	return;
}

RPN::~RPN()
{
	return;
}

RPN & RPN::operator=(RPN const & copy)
{
	(void)copy;
	return (*this);
}


int RPN::size(void)
{
	return (_stack.size());
}

void RPN::push(float value)
{
	_stack.push(value);
}

void RPN::add(void)
{
	float a = _stack.top();
	_stack.pop();
	float b = _stack.top();
	_stack.pop();
	_stack.push(a + b);
}

void RPN::sub(void)
{
	float a = _stack.top();
	_stack.pop();
	float b = _stack.top();
	_stack.pop();
	_stack.push(b - a);
}

void RPN::mul(void)
{
	float a = _stack.top();
	_stack.pop();
	float b = _stack.top();
	_stack.pop();
	_stack.push(a * b);
}

void RPN::div(void)
{
	float a = _stack.top();
	_stack.pop();
	float b = _stack.top();
	_stack.pop();
	if (a == 0)
		throw std::exception();
	_stack.push(b / a);
}

void RPN::print(void)
{
	std::cout << _stack.top() << std::endl;
}