/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:22:11 by mpignet           #+#    #+#             */
/*   Updated: 2023/03/17 16:35:56 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;
	public:
		AForm(void);
		AForm(const std::string& name, const int signGrade, const int execGrade);
		AForm(const AForm&);
		~AForm(void);

		AForm&				operator=(const AForm&);
		const std::string&	getName() const;
		const int&			getSignGrade() const;
		const int&			getExecGrade() const;
		bool				getSigned() const;

		virtual void	beSigned(Bureaucrat&);
		virtual void	check_exec(Bureaucrat const & executor) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
		
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
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
	class TooLowToExecException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream&, const AForm&);

#endif