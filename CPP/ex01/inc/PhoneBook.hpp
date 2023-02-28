/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:12:01 by mpignet           #+#    #+#             */
/*   Updated: 2023/02/28 15:22:37 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <limits>
# include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	add_contact(void);
	void	search(void);
private:
	Contact contacts[8];
	int	nbr_contacts;
};

#endif