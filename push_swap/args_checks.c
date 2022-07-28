/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:39:46 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/28 14:58:12 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			return (1);
	return (0);
}

int	check_double(t_list **lst, int elem)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->content == elem)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sizeint(char *str)
{
	char	*dst;
	int		diff;

	dst = ft_itoa(ft_atoi(str));
	diff = ft_strcmp(str, dst);
	if (diff != 0)
		return (free(dst), 1);
	return (free(dst), 0);
}

int	check_integers(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
			i++;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	return (0);
}
