/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:39:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/05 15:37:03 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_element(t_list **lst, char *str)
{
	int	element;

	element = ft_atoi(str);
	if (check_double(lst, element))
		return (1);
	ft_lstadd_back(lst, ft_lstnew(element));
	return (0);
}

static int	split_add(t_list **lst, char *str)
{
	char **strs;
	int	j;
	
	strs = ft_split(str, ' ');
	j = -1;
	while (strs[++j])
	{
		if (check_integers(strs[j]) || check_sizeint(strs[j]) 
			|| add_element(lst, strs[j]))
			return (1);
		free(strs[j]);
	}
	free(strs);
	return (0);
}

int	parse(t_list **lst, int ac, char **av)
{
	int		i;
	
	i = 1;
	while (i < ac)
	{
		if (check_spaces(av[i]))
		{
			if(split_add(lst, av[i]))
				return (1);	
		}
		else
		{
			if (check_integers(av[i]) || check_sizeint(av[i]) 
				|| add_element(lst, av[i]))
				return (1);
		}
		i++;
	}
	return (0);
}