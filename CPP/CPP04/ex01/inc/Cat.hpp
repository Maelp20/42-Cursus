/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:17:15 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 17:57:30 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat&);
	Cat& operator=(const Cat&);
	virtual ~Cat(void);

	void		makeSound() const;
	Brain*		getBrain();
private:
	Brain*	_brain;
} ;

#endif