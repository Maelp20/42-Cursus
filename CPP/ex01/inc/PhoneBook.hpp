/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:12:01 by mpignet           #+#    #+#             */
/*   Updated: 2023/02/27 19:08:31 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <limits>

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	add_contact(void);
	void	search(void);
	//void	my_exit(void);
private:
	Contact contacts[8];
	int	nbr_contacts;
};

#endif