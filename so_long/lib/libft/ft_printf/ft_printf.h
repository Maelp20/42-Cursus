/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:55:14 by mpignet           #+#    #+#             */
/*   Updated: 2022/05/16 18:54:45 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *entree, ...);
void	ft_putchar(char c);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_print_ptr(unsigned long ptr);
int		ft_printnbr(int n);
int		ft_printnbr_unsigned(unsigned int n);
int		ft_printhexa(unsigned int nbr, int format);

#endif