/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:12:06 by mpignet           #+#    #+#             */
/*   Updated: 2023/02/27 19:13:26 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
public:
	Contact(void);
	~Contact(void);
	std::string	get_first_name(void);
	std::string	get_last_name(void);
	std::string	get_nickname(void);
	std::string	get_phone_nbr(void);
	std::string	get_secret(void);
	void	set_contact(std::string input, int elem);
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_nbr;
	std::string secret;
};

#endif