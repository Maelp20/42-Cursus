/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:05:56 by mpignet           #+#    #+#             */
/*   Updated: 2023/04/28 16:02:37 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <exception>

class Base
{
	public :
		virtual ~Base(void);
} ;

class	A :public Base {} ;
class	B :public Base {} ;
class	C :public Base {} ;
class	D :public Base {} ;

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

# endif