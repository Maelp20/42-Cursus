/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:28:27 by mpignet           #+#    #+#             */
/*   Updated: 2023/04/28 17:28:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void    iter(T * array, int size, void (*f)(T const &)) {
    for (int i = 0; i < size; i++) {
        (*f)(array[i]);
    }
    return ;
}

template<typename T>
void    display(T const & elem) {
    std::cout << elem << std::endl;
}

# endif