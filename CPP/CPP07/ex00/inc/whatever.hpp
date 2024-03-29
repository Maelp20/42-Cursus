/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:28:27 by mpignet           #+#    #+#             */
/*   Updated: 2023/04/28 17:28:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void    swap(T & a, T & b) {
    T   tmp = a;
    a = b;
    b = tmp;
    return ;
}

template<typename T>
T const &   min(T const & a, T const & b) {
    return (a < b ? a : b);
}

template<typename T>
T const &   max(T const & a, T const & b) {
    return (a > b ? a : b);
}

# endif