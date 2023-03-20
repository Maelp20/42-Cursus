/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:22:11 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/20 14:23:37 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:
	public:
		typedef struct	s_form_types
		{
			std::string	name;
			AForm*	(Intern::*f)(const std::string& target);
		} t_form_types ;

		Intern(void);
		Intern(const Intern&);
		~Intern(void);

		Intern&			operator=(const Intern&);

		AForm* makeForm(const std::string& name, const std::string& target);
		AForm* makeShrubberyCreation(const std::string& target);
		AForm* makeRobotomyRequest(const std::string& target);
		AForm* makePresidentialPardon(const std::string& target);
};

#endif