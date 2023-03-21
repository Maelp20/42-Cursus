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

static class	ScalarConverter
{
	private:
	public:
		 ScalarConverter(void);
		 ScalarConverter(const  ScalarConverter&);
		~ ScalarConverter(void);

		 ScalarConverter&			operator=(const  ScalarConverter&);
		

};

#endif