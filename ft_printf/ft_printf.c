/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:19:10 by mpignet           #+#    #+#             */
/*   Updated: 2022/05/13 12:37:15 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_dispatch(char c, va_list arg, size_t len)
{
	if(c == 'c')
		len = ft_printchar((char)va_args (arg, int), len);
	else if(c == 's')
		len = ft_printstr((char *)va_args (arg, int), len);
	else if(c == 'p')
		len = ft_printhexa((long long)va_args (arg, int), len);		
	else if(c == 'd')
		len = ft_printnbrd((double)va_args (arg, int), len);
	else if(c == 'i')
		len = ft_printnbri((int)va_args (arg, int), len);
	else if(c == 'u')
		len = ft_printnbru((long long)va_args (arg, int), len);
	else if(c == 'x')
		ft_x(c);
	else if(c == 'X')
		ft_X(c);
	else if(c == '%')
		ft_putchar(c);
	return (len)
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*Fonction principale : on declare une va_liste et on l'initialise. 
On parcours la string entree en argument et on l'imprime, sauf si on tombe sur
un '%'. Si '%', on envoie le char suivant dans ft_dispatch pour envoyer ensuite
dans la fonction necessaire selon le type de variable a afficher. On incremente 
len quand on affiche un caractere. */

int	ft_printf(const char *entree, ...)
{
	va_list	arg;
	size_t	i;
	size_t	len;

	va_start (arg, entree);
	i = 0;
	len = 0;
	while (entree[i])
	{
		if (entree[i] == '%')
			len = ft_dispatch(entree[i + 1], arg, len);
		else
		{
			ft_putchar(entree[i]);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
