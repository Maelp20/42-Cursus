/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:12 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/14 14:26:19 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;
	bool		_equiped;
public:
	AMateria(void);
	AMateria(const AMateria&);
	AMateria(std::string const & type);
	AMateria&	operator=(const AMateria&);
	virtual ~AMateria();

	bool	alreadyEquiped() const;
	void	isEquiped();
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
} ;


#endif