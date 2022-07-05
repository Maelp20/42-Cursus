/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:39:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/05 13:47:02 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_integers(char *str)
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

static int	check_sizeint(char *str)
{
	char *dst;
	int	diff;
	dst = ft_itoa(ft_atoi(str));
	diff = ft_strcmp(str, dst);
	if (diff != 0)
		return (1);
	return (0);
}

static int	check_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			return (1);
	return (0);
}

static int	split_add(t_list *lst, char *str)
{
	char **strs;
	int	j;
	
	strs = ft_split(str, ' ');
	j = -1;
	while (strs[++j])
	{
		if (check_integers(strs[j]) || check_sizeint(strs[j]))
			return (1);
		add_element(&lst, strs[j]);
		free(strs[j]);
	}
	free(strs);
	return (0);
}

int	check_double()
{
	
}

int	args_check(t_list *lst, int ac, char **av)
{
	int		i;
	int		j;
	char	**stock;
	
	i = 1;
	stock = malloc (sizeof (char *) * ac);
	if (!stock)
		return (1);
	stock[ac - 1] = NULL;
	while (i < ac)
	{
		if (check_spaces(av[i]))
		{
			j = split_add(lst, av[i]);
			if(j == 1)
				return (1);
		}
		else
		{
			if (check_integers(av[i]) || check_sizeint(av[i]))
				return (1);
			else
				add_element(&lst, av[i]);
		}
		i++;
	}
	return (0);
}