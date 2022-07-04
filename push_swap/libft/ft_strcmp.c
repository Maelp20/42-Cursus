/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:53:21 by mpignet           #+#    #+#             */
/*   Updated: 2022/06/24 15:44:23 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;

	a = 0;
	while ((s1[a] != '\0') && (s1[a] == s2[a]))
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}