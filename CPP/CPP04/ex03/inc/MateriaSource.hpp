/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:12 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/14 14:26:19 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MateriaSource_HPP
# define MateriaSource_HPP

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:

public:
	MateriaSource(void);
	MateriaSource(const std::string& name);
	MateriaSource(const MateriaSource&);
	MateriaSource&	operator=(const MateriaSource&);
	~MateriaSource();

	const std::string& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, IMateriaSource& target);
} ;

#endif