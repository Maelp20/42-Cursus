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
	if (str.size() > 10)
		return (0);
	if ((str[0] == '-' || str[0] == '+') && str != "-inff" && str != "+inff" && str != "-inf" && str != "+inf")
		str = str.substr(1, str.length() - 1);
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	is_float(std::string& str)
{
	if (str.size() > 10)
		return (0);
	if ((str[0] == '-' || str[0] == '+') && str != "-inff" && str != "+inff" && str != "-inf" && str != "+inf")
		str = str.substr(1, str.length() - 1);
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return (0);
	}
	return (1);
}

int	is_double(std::string& str)
{
	if (str.size() > 10)
		return (0);
	if ((str[0] == '-' || str[0] == '+') && str != "-inff" && str != "+inff" && str != "-inf" && str != "+inf")
		str = str.substr(1, str.length() - 1);
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != 'l'
			&& str[i] != 'L' && str[i] != 'd' && str[i] != 'D')
			return (0);
	}
	return (1);
}

char	convert_char(std::string& str)
{
	return (str[0]);
}

int	convert_int(std::string& str)
{
	return (atoi(str.c_str()));
}

float	convert_float(std::string& str)
{
	return (atof(str.c_str()));
}

double	convert_double(std::string& str)
{
	return (atof(str.c_str()));
}

void	ScalarConverter::convert(std::string& str)
{
	char c;
	int	i;
	float f;
	double d;

	if (is_char(str)) {
		c = convert_char(str);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (is_int(str)) {
		i = convert_int(str);
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	else if (is_float(str)) {
		f = convert_float(str);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
	}
	else if (is_double(str)) {
		d = convert_double(str);
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
	}
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
		return;
	}
	try {
		if (c < 32 || c > 126)
			throw ScalarConverter::NonDisplayableException();
		std::cout << "char: " << c << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "char: " << e.what() << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
	std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
	return ;
}


/*--------------------------------EXCEPTIONS-----------------------------------*/

const char*	ScalarConverter::NonDisplayableException::what(void) const throw()
{
	return ("Non displayable");
}
