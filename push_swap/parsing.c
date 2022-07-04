/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:39:46 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/04 14:43:31 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_element(t_list **lst, char *str)
{
	int	element;

	element = ft_atoi(str);
	ft_lstadd_back(lst, ft_lstnew(element));
}

// int	parse(t_list *lst, int ac, char **av)
// {
// 	int		i;
// 	int		j;
// 	char	**strs;
// 	char	**tab;
	
// 	i = 0;
// 	while (i < ac)
// 	{
// 		if (check_spaces(av[i]))
// 		{
// 			strs = ft_split(av[i], ' ');
// 			j = -1;
// 			while (strs[++j])
// 			{
// 				add_element(&lst, strs[j]);
// 				free(strs[j]);	
// 			}
// 			free(strs);
// 		}
// 		else
// 			add_element(&lst, av[i]);
// 		i++;
// 	}
// 	return (0);
// }