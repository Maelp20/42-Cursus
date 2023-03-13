/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:09:46 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/13 17:54:06 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
public:
	Brain(void);
	Brain(const Brain&);
	Brain& operator=(const Brain&);
	~Brain(void);

	void		setIdeas(const std::string&);
	std::string	getIdeas();
private:
	std::string ideas[100];
} ;

# endif