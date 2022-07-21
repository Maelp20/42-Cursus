/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:54:48 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/21 12:58:12 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int tab_sorted(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	sort_int_tab(int *tab, int size)
{
	int i;
	int swap;
	
	swap = 0;
	while (!tab_sorted(tab, size))
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
	}
}

int	lst_sorted(t_list *lst)
{
	t_list	*tmp;
	
	tmp = lst;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_median(t_list *lst, int chunk_size)
{
	int	median;
	int	i;
	int	size;
	int	*buff;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	if (chunk_size)
		size = chunk_size;
	else
		size = ft_lstsize(lst);
	buff = (int *)malloc(sizeof(int) * size);
	while (size > 0)
	{
		buff[i] = tmp->content;
		tmp = tmp ->next;
		i++;
		size --;
	}
	sort_int_tab(buff, i);
	median = buff[i / 2];
	free(buff);
	return (median);
}