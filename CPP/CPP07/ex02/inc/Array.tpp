/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:17:07 by maelpignet        #+#    #+#             */
/*   Updated: 2023/05/04 15:50:26 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

/*                                 CONSTRUCTORS                               */

template<typename T>
Array<T>::Array(void) : _array_ptr(new T[0]), _size(0) { return ; }

template<typename T>
Array<T>::Array(unsigned int n) : _array_ptr(new T[n]), _size(n)
{
    return ;
}

template<typename T>
Array<T>::Array(Array const & src)
{
   _size = src._size;
   _array_ptr = new T[_size];
    for (unsigned int i = 0; i <_size; i++) {
       _array_ptr[i] = src._array_ptr[i];
    }
    return ;
}

/*                                 DESTRUCTOR                                 */

template<typename T>
Array<T>::~Array()
{
    delete[] _array_ptr;
    return ;
}

/*                                 OPERATORS                                   */

template<typename T>
Array<T> &  Array<T>::operator=(Array const & rhs)
{
   _size = rhs._size;
    delete[]_array_ptr;
   _array_ptr = new T[_size];
    for (unsigned int i = 0; i <_size; i++) {
       _array_ptr[i] = rhs._array_ptr[i];
    }
    return (*this);
}

template<typename T>
T &  Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw OutOfRangeException();
    return (_array_ptr[i]);
}

/*                                 MEMBER FUNCTIONS                            */

template<typename T>
unsigned int Array<T>::size()
{
    return (_size);
}

/*                                  EXCEPTIONS                                  */

template<typename T>
const char *Array<T>::OutOfRangeException::what(void) const throw()
{
    return ("Requested index is out of range !");
}

# endif