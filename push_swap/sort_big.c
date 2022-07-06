/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:25:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/06 10:18:32 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void printlist(t_list *lst, char id);

static int sorted(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static void	sort_int_tab(int *tab, int size)
{
	int i;
	int swap;
	
	swap = 0;
	while (sorted(tab, size))
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

static int	find_median(t_list *lst)
{
	int	median;
	int	i;
	int	*buff;
	t_list	*tmp;

	buff = (int *)malloc(sizeof(int) * ft_lstsize(lst));
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
	printf ("MEDIAN = %d\n", median);
	free(buff);
	return (median);
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
    t_list *move;
	int		median;

	median = find_median(*stack_a);
	move = *stack_a;
	printlist(move, 'm');
    while(move)
	{
		if (move->content < median)
			ft_push(&move, stack_b, 'b');
		move = move->next;
	}
}