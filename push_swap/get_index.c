/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:46:41 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/24 16:58:21 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	get_cost_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		size;
	int		cost;
	
	tmp2 = *stack_b;
	size = ft_lstsize(*stack_a);
	while (*stack_b)
	{
		tmp = *stack_a;
		cost = 0;
		while (tmp)
		{
			if (tmp->pos == (*stack_b)->target_pos)
			{
				if (cost > size / 2)
					cost = size - cost;
				(*stack_b)->cost_a = cost;
			}
			tmp = tmp->next;
			cost++;
		}
		*stack_b = (*stack_b)->next;
	}
	*stack_b = tmp2;
}

void	get_cost_b(t_list **stack_b)
{
	t_list *tmp;
	int		size;

	tmp = *stack_b;
	size = ft_lstsize(*stack_b);
	while (*stack_b)
	{
		if ((*stack_b)->pos <= size / 2)
			(*stack_b)->cost_b = (*stack_b)->pos;
		else
			(*stack_b)->cost_b = size - (*stack_b)->pos;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = tmp;
}

void	get_index(t_list **stack_a)
{
	int	i;
	int	size;
	int	*buff;
	t_list	*tmp;
	t_list	*tmp2;

	i = 0;
	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	buff = (int *)malloc(sizeof(int) * size);
	while (size > 0)
	{
		buff[i] = tmp->content;
		tmp = tmp->next;
		i++;
		size --;
	}
	sort_int_tab(buff, i);
	tmp2 = *stack_a;
	size = i;
	while (*stack_a)
	{
		i = 0;
		while (i <= size)
		{
			if ((*stack_a)->content == buff[i])
				(*stack_a)->index = i + 1;
			i++;
		}
		*stack_a = (*stack_a)->next;	
	}
	*stack_a = tmp2;
	free(buff);
}