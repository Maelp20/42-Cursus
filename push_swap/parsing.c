/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:39:46 by mpignet           #+#    #+#             */
/*   Updated: 2022/06/20 16:56:20 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_spaces(char *av)
{
	int	i;

	i = -1;
	while (av[++i])
		if (av[i] == ' ')
			return (1);
	return (0);
}

static void	add_element(t_list **lst, char *str)
{
	int	element;
	t_list *new;

	element = ft_atoi(str);
	new = ft_lstnew(element);
	ft_lstadd_back(lst, new);
}

void	parse(t_list *lst, int ac, char **av)
{
	int		i;
	int		j;
	char	**strs;
	
	i = 0;
	while (i < ac)
	{
		if (check_spaces(av[i]))
		{
			strs = ft_split(av[i], ' ');
			j = -1;
			while (strs[++j])
			{
				add_element(&lst, strs[j]);
				free(strs[j]);	
			}
			free(strs);
		}
		else
			add_element(&lst, av[i]);
		i++;
	}
}