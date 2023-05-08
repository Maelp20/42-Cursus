/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:34:27 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/08 19:34:06 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//ex00 : map
//ex01 : stack
//ex02 : vector and deque

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
		std::map<std::string, float> _input;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & copy);
		~BitcoinExchange();

		BitcoinExchange & operator=(BitcoinExchange const & copy);
}

#endif