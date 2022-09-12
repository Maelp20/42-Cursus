/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:38:54 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/06 16:59:32 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc_spec(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count);
	return (ptr);
}

char	*ft_strchr_spec(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_spec(char *s1, char *s2)
{
	char	*dest;
	int		len;
	int		i;

	if (!s1)
	{
		s1 = (char *)ft_calloc(sizeof(char), 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!dest)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			dest[i] = s1[i];
	while (*s2)
		dest[i++] = *s2++;
	dest[len] = '\0';
	free(s1);
	return (dest);
}
