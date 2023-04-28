/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:22:11 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/17 16:35:56 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SERIALIZER_HPP
# define  SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct Data
{
	int x;
	int	y;
} Data;

class	Serializer
{
	private:
	public:
		Serializer(void);
		Serializer(const  Serializer&);
		~ Serializer(void);

		Serializer&			operator=(const  Serializer&);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif