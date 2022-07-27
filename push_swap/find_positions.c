/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:41:18 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/24 17:23:19 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		max_index(t_list **stack)
{
	t_list *tmp;
	int	max_index;

	tmp = *stack;
	max_index = 0;
	while(tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}

int		min_pos(t_list **stack)
{
	t_list *tmp;
	int	min_index;
	int	min_pos;

	tmp = *stack;
	min_index = 2147483647;
	while(tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}

void	find_target_pos(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	t_list *tmp2;
	int		next_index;

	tmp2 = *stack_b;
	while (*stack_b)
	{
		tmp = *stack_a;
		next_index = 2147483647;
		while (tmp)
		{
			if ((*stack_b)->index < tmp->index)
			{
				if (tmp->index < next_index)
				{
					next_index = tmp->index;
					(*stack_b)->target_pos = tmp->pos;
				}
			}
			else if ((*stack_b)->index > max_index(stack_a))
				(*stack_b)->target_pos = min_pos(stack_a);
			tmp = tmp->next;
		}
		*stack_b = (*stack_b)->next;
	}
	*stack_b = tmp2;
}

void	find_positions(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		pos;

	tmp = *stack_a;
	tmp2 = *stack_b;
	pos = 0;
	while (*stack_a)
	{
		(*stack_a)->pos = pos;
		*stack_a = (*stack_a)->next;
		pos++;
	}
	*stack_a = tmp;
	pos = 0;
	while (*stack_b)
	{
		(*stack_b)->pos = pos;
		*stack_b = (*stack_b)->next;
		pos++;
	}
	*stack_b = tmp2;
}