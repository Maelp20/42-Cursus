/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_args_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:05:20 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/04 11:08:02 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			return (1);
	return (0);
}

int	args_check(t_list *lst, int ac, char **av)
{
	int		i;
	char	**buff;

	buff = malloc (sizeof (char *) * ac);
	buff[ac - 1] = NULL;
	i = 1;
	while (i < ac)
	{
		if (check_spaces(av[i]))
		{
			
		}
	}	
}