/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:25:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/05 15:30:59 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

    while(move)
	{
		if ((move->content) < median)
			ft_push(&move, stack_b, 'b');
		else
			move = move->next;
	}
}