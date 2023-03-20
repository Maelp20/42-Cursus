/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:22:11 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/20 14:23:37 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, const int grade);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat(void);

		Bureaucrat&			operator=(const Bureaucrat&);
		const std::string&	getName() const;
		const int&			getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm&);
		void	executeForm(AForm const & form);
		
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
	
};

std::ostream&	operator<<(std::ostream&, const Bureaucrat&);

#endif