/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:27:16 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/06 16:39:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_nb_words(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			nb++;
		i++;
	}
	return (nb);
}

static int	ft_len(char const *s, char c, size_t i)
{
	int	len;

	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (len);
		i++;
		len++;
	}
	return (len);
}

static void	ft_free_all(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	ft_fill(char **dest, char const *s, char c)
{
	size_t	i;
	size_t	x;
	size_t	len;

	i = 0;
	x = 0;
	while (s[i])
	{
		len = 0;
		if (s[i] != c)
		{
			len = ft_len(s, c, i);
			dest[x] = ft_substr(s, i, len);
			if (!dest[x])
			{
				ft_free_all(dest);
				return ;
			}
			x++;
			i += len;
		}
		else
			i += len + 1;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		nb;

	if (!s)
		return (NULL);
	nb = ft_nb_words(s, c);
	dest = malloc (sizeof(char *) * (nb + 1));
	if (!dest)
		return (NULL);
	ft_fill(dest, s, c);
	dest[nb] = 0;
	return (dest);
}
