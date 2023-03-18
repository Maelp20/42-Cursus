/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:22:11 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/17 16:35:56 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;
	public:
		Form(void);
		Form(const std::string& name, const int signGrade, const int execGrade);
		Form(const Form&);
		~Form(void);

		Form&				operator=(const Form&);
		const std::string&	getName() const;
		const int&			getSignGrade() const;
		const int&			getExecGrade() const;
		bool				getSigned() const;

		void	beSigned(Bureaucrat&);
		
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
	class AlreadySignedException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream&, const Form&);

#endif