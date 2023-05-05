/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:33:05 by mpignet           #+#    #+#             */
/*   Updated: 2023/05/05 19:29:56 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <cmath>
# include <algorithm>

class Span
{
	private:
		std::vector<int>	_nbrs;
		unsigned int		_max_size;
	public:
		Span(void);
		Span(unsigned int);
		Span(Span const &);
		~Span(void);

		Span & operator=(Span const &);

		unsigned int const &	get_max_size() const;
		int						shortestSpan();
		int						longestSpan();
		void					addNumber(int const &);

} ;

#endif
