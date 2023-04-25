/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:22:11 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/17 16:35:56 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SCALARCONVERTER_HPP
# define  SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <string>
# include <limits>
# include <cerrno>

class	ScalarConverter
{
	private:
	public:
		ScalarConverter(void);
		ScalarConverter(const  ScalarConverter&);
		~ ScalarConverter(void);

		 ScalarConverter&			operator=(const  ScalarConverter&);
		
		static void	convert(std::string& str);

		class	NonDisplayableException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif