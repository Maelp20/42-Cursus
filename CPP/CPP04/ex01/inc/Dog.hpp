/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:18 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 17:57:35 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog&);
	Dog& operator=(const Dog&);
	virtual ~Dog(void);

	void		makeSound() const;
	Brain*		getBrain();
private:
	Brain*	_brain;
} ;

#endif