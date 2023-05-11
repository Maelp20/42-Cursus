/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:41:47 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/11 18:00:43 by mpignet          ###   ########.fr       */
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

void RPN::push(float value)
{
	_stack.push(value);
}

void RPN::add(void)
{
	if (_stack.size() < 2)
		throw std::exception();
	float a = _stack.top();
	_stack.pop();
	float b = _stack.top();
	_stack.pop();
	_stack.push(a + b);
}

void RPN::sub(void)
{
	if (_stack.size() < 2)
		throw std::exception();
	float a = _stack.top();
	_stack.pop();
	float b = _stack.top();
	_stack.pop();
	_stack.push(b - a);
}

void RPN::mul(void)
{
	if (_stack.size() < 2)
		throw std::exception();
	float a = _stack.top();
	_stack.pop();
	float b = _stack.top();
	_stack.pop();
	_stack.push(a * b);
}

void RPN::div(void)
{
	if (_stack.size() < 2)
		throw std::exception();
	float a = _stack.top();
	_stack.pop();
	float b = _stack.top();
	_stack.pop();
	if (a == 0)
		throw std::exception();
	_stack.push(b / a);
}

int RPN::size(void)
{
	return (_stack.size());
}

void RPN::print(void)
{
	if (_stack.size() != 1)
		throw std::exception();
	std::cout << _stack.top() << std::endl;
}