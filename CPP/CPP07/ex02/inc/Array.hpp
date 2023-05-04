/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:28:27 by mpignet           #+#    #+#             */
/*   Updated: 2023/04/28 17:28:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array {
    public:
        Array();
        Array(unsigned int) ;
        Array(Array const &);
        ~Array();

        Array & operator=(Array const &);
        T &     operator[](unsigned int);
        T     operator[](unsigned int) const;
        unsigned int size() ;
    private:
        T               *_array_ptr;
        unsigned int    _size;

    class OutOfRangeException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
} ;

# endif