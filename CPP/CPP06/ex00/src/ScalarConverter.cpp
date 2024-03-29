/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:47:32 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/20 16:29:50 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter created" << std::endl;
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	std::cout << "ScalarConverter created by copy" << std::endl;
	*this = src;
	return;
}

/*---------------------------------DESTRUCTOR---------------------------------*/

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destroyed" << std::endl;
	return;
}

/*--------------------------------OPERATORS-----------------------------------*/

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
	(void)src;
	std::cout << "ScalarConverter assignment operator called" << std::endl;
	return(*this);
}


/*--------------------------------ACCESSORS-----------------------------------*/


/*------------------------------MEMBER FUNCTIONS------------------------------*/


int	is_char(std::string& str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (1);
	return (0);
}

int	is_int(std::string& str)
{
	std::string tmp = str;
	if (tmp.size() > 11)
		return (0);
	if (tmp[0] == '-' || tmp[0] == '+')
		tmp = tmp.substr(1, tmp.length() - 1);
	for (size_t i = 0; i < tmp.length(); i++) {
		if (!isdigit(tmp[i]))
			return (0);
	}
	return (1);
}

int	is_float(std::string& str)
{
	std::string tmp = str;
	if (tmp.size() > 11)
		return (0);
	if (tmp[0] == '-' || tmp[0] == '+')
		tmp = tmp.substr(1, tmp.length() - 1);
	for (size_t i = 0; i < tmp.length(); i++) {
		if (!isdigit(tmp[i]) && tmp[i] != '.' && tmp[i] != 'f')
			return (0);
	}
	double	tmp2 = strtof(str.c_str(), NULL);
	if (tmp2 > std::numeric_limits<float>::max() || tmp2 < std::numeric_limits<float>::min())
		return (0);
	return (1);
}

int	is_double(std::string& str)
{
	std::string tmp = str;
	if (tmp.size() > 11)
		return (0);
	if (tmp[0] == '-' || tmp[0] == '+')
		tmp = tmp.substr(1, tmp.length() - 1);
	for (size_t i = 0; i < tmp.length(); i++) {
		if (!isdigit(tmp[i]) && tmp[i] != '.' && tmp[i] != 'f' && tmp[i] != 'l'
			&& tmp[i] != 'L' && tmp[i] != 'd' && tmp[i] != 'D')
			return (0);
	}
	return (1);
}

char	convert_char(std::string& str)
{
	char c = str[0];
	try {

		if (atoi(str.c_str()) < 32 || atoi(str.c_str()) > 126)
			throw ScalarConverter::NonDisplayableException();
		std::cout << "char: '" << c << "'" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "char: " << e.what() << std::endl;
	}
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(c) << std::endl;
	return (str[0]);
}

int	convert_int(std::string& str)
{
	long int	tmp = strtol(str.c_str(), NULL, 10);
	int			i = atoi(str.c_str());
	bool		overflow = false;


	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
		overflow = true;
	try {
		if (i < 32 || i > 126)
			throw ScalarConverter::NonDisplayableException();
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "char: " << e.what() << std::endl;
	}
	if (overflow)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(i) << std::endl;
	return (i);
}

float	convert_float(std::string& str)
{
	float	f = strtof(str.c_str(), NULL);
	bool	overflow = false;

	if (errno == ERANGE)
		overflow = true;
	try {
		if (f < 32 || f > 126 || overflow == true)
			throw ScalarConverter::NonDisplayableException();
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "char: " << e.what() << std::endl;
	}
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (overflow)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
	std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(f) << std::endl;
	return (f);
}

double	convert_double(std::string& str)
{
	double	d = strtod(str.c_str(), NULL);
	bool	overflow = false;

	if (errno == ERANGE)
		overflow = true;
	try {
		if (d < 32 || d > 126 || overflow == true)
			throw ScalarConverter::NonDisplayableException();
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "char: " << e.what() << std::endl;
	}
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (overflow)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(d) << "f" << std::endl;
	if (overflow)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
	return (d);
}

void	ScalarConverter::convert(std::string& str)
{
	char c;
	int	i;
	float f;
	double d;

	if (is_char(str))
		c = convert_char(str);
	else if (is_int(str))
		i = convert_int(str);
	else if (is_float(str))
		f = convert_float(str);
	else if (is_double(str))
		d = convert_double(str);
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str == "nanf" || str == "nan" || str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff") {
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str << std::endl;
		}
		else {
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
	}
	return ;
}


/*--------------------------------EXCEPTIONS-----------------------------------*/

const char*	ScalarConverter::NonDisplayableException::what(void) const throw()
{
	return ("Non displayable");
}
