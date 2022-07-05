/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:25:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/05 14:05:16 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_tab(int *tab, int size)
{
	int	a;
	int	tmp;

	a = 1;
	if (size != 0)
	{
		while (a <= size)
		{
			if (tab[a] < tab[a - 1])
			{
				tmp = tab[a];
				tab[a] = tab[a - 1];
				tab[a - 1] = tmp;
				a = 0;
			}
			a++;
		}
	}
}

int	find_median(t_list *lst)
{
	int	median;
	int	i;
	int	*buff;
	t_list	*tmp;

	buff = (int)malloc(sizeof(int) * ft_lstsize(lst));
	i = 0;
	tmp = lst;
	while (tmp)
	{
		buff[i] = tmp->content;
		tmp = tmp ->next;
		i++;
	}
	sort_int_tab(buff, i);
	median = buff[i / 2];
	free(buff);
	return (median);
}

void	sort_big(t_list **lst, t_list **b)
{
    t_list *move;
	int		median;

	median = find_median(&lst);
	move = *lst;

    
}