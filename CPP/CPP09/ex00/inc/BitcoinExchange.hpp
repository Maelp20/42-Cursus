/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:34:27 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/22 16:00:51 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//ex00 : map

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <limits>
# include <cstdlib>
# include <algorithm>
# include <iterator>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
		std::fstream	_input;
		std::fstream	_data_ref;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & copy);
		~BitcoinExchange();

		BitcoinExchange & operator=(BitcoinExchange const & copy);

		void	readInput(std::string filename);
		void	readData(void);
		std::fstream & get_input(void);
		std::fstream & get_data_ref(void);
} ;

#endif