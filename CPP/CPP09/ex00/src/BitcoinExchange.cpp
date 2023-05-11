/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:34:30 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/11 17:24:58 by mpignet          ###   ########.fr       */
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
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		return (1);
	if (date.find_first_of("-") != 4 || date.find_last_of("-") != 7 || std::count(date.begin(), date.end(), '-') != 2)
		return (1);
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	if (year.size() != 4 || month.size() != 2 || day.size() != 2)
		return (1);
	if (month > "12" || month < "01")
		return (1);
	if (month == "02" && day > "28" && year != "2004" && year != "2008" && year != "2012"
		&& year != "2016" && year != "2020" && year != "2024" && year != "2028" && year != "2032" && year != "2036")
		return (1);
	if (month == "02" && day > "29")
		return (1);
	if ((month == "04" || month == "06" || month == "09" || month == "11") && day > "30")
		return (1);
	if (day > "31" || day < "01")
		return (1);
	return (0);
}

int	check_nbr(std::string nbr)
{
	if (nbr.find_first_not_of("0123456789.-") != std::string::npos)
		return (1);
	if (nbr.find_first_of("-") != 0 && nbr.find_first_of("-") != std::string::npos)
		return (1);
	if (nbr.find_first_of(".") == 0 || nbr.find_first_of(".") == nbr.size() - 1)
		return (1);
	if (std::count(nbr.begin(), nbr.end(), '.') > 1 || std::count(nbr.begin(), nbr.end(), '-') > 1)
		return (1);
	if (nbr[0] == '-' && nbr[1] == '0' && nbr.find_first_not_of("0.-") == std::string::npos)
		return (1);
	if (nbr[0] == '-' && nbr[1] == '.')
		return (1);
	return (0);
}

void	BitcoinExchange::readInput(std::string filename)
{
	std::string		line;
	std::string		date;
	std::fstream	file;
	float			nbr;
	int				pos = 0;

	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: Could not open file " << filename << std::endl;
		exit(1);
	}
	if (file.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Error: Empty file " << filename << std::endl;
		exit(1);
	}
	while (std::getline(file, line))
	{
		if (line == "date | value")
			continue;
		pos = line.find(" | ");
		if (pos != 10) {
			if (line.empty())
				std::cout << "Error: Empty line in file" << std::endl;
			else
				std::cout << "Error: Bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, pos);
		if (check_date(date)) {
			std::cout << "Error: Bad input => " << date << std::endl;
			continue;
		}
		else if	(date < "2009-01-02") {
			std::cout << date << ": Error: No data available for this date." << std::endl;
			continue;
		}
		else if (check_nbr(line.substr(pos + 3))) {
			std::cout << "Error: Bad input => " << line.substr(pos + 2) << std::endl;
			continue;
		}
		nbr = std::atof(line.substr(pos + 3).c_str());
		//std::cout << "\x1B[33m" << "date: " << date << " nbr: " << nbr << "\033[0m\t\t" << std::endl;
		if (nbr < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (nbr > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else if (_data.find(date) != _data.end())		
			std::cout << date << " => " << nbr << " = " << nbr * _data[date] << std::endl;
		else
			for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
				if (it->first > date && it != _data.begin()) {
					it--;
					std::cout << date << " => " << nbr << " = " << nbr * it->second << std::endl;
					break;
				}
				if (it == --_data.end()) {
					std::cout << date << " => " << nbr << " = " << nbr * it->second << std::endl;
				}
			}
	}
}

void	BitcoinExchange::readData(void)
{
	std::string line;
	std::string date;
	std::fstream file;
	float value;

	file.open("./data.csv");
	if (!file.is_open())
	{
		std::cout << "Error: Could not open file data.csv" << std::endl;
		exit(1);
	}
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		ss >> value;
		_data[date] = value;
	}
	_data.erase("date");
	if (_data.empty())
	{
		std::cout << "Error: No data available." << std::endl;
		exit(1);
	}
}