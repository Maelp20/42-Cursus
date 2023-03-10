/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:21:07 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/10 15:50:11 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

public:
	Fixed(void);
	Fixed(const Fixed&);
	Fixed&	operator=(const Fixed&);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int	_value;
	const static int	_fract_bits = 8;
} ;

#endif