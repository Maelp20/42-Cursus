/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:34:30 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/10 17:14:26 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	return;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
	*this = copy;
	return;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & copy)
{
	(void)copy;
	return (*this);
}

int	check_date(std::string date)
{
	if (date.size() != 10)
		return (1);
	if (date[4] != '-' || date[7] != '-')
		return (1);
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	if (year.size() != 4 || month.size() != 2 || day.size() != 2)
		return (1);
	if (month > "12" || month < "01")
		return (1);
	if (month == "02" && day > "28")
		return (1);
	if ((month == "04" || month == "06" || month == "09" || month == "11") && day > "30")
		return (1);
	if (day > "31" || day < "01")
		return (1);
	return (0);
}

void	BitcoinExchange::readInput(std::string filename)
{
	std::string line;
	std::string date;
	std::fstream file;
	file.open(filename.c_str());
	float nbr;

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, '|');
		ss >> nbr;
		date.erase(date.size() - 1);
		if (date == "date")
			continue;
		if (check_date(date)) {
			std::cout << "Error: Bad input => " << date << std::endl;
			continue;
		}
		if (nbr < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (nbr > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (_data.find(date) != _data.end())
			std::cout << date << " => " << nbr << " = " << nbr * _data[date] << std::endl;
		else
			for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
				if (it->first > date) {
					std::cout << date << " => " << nbr << " = " << nbr * it->second << std::endl;
					break;
				}
			}
	}
}

void	BitcoinExchange::readData(void)
{
	std::string line;
	std::string date;
	std::fstream file;
	file.open("./data.csv");
	float value;

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		ss >> value;
		_data[date] = value;
	}
	_data.erase("date");
	// for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
	// 	std::cout << it->first << " => " << it->second << std::endl;
	// }
	// std::cout << std::endl;
}
