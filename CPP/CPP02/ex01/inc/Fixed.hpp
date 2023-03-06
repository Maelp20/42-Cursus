/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:21:07 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/06 16:37:40 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

public:
	Fixed(void);
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed&);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed&	operator=(const Fixed&);
	float	toFloat(void) const;
	int		toInt(void) const;
private:
	int	value;
	const static int	size = 8;
} ;

#endif