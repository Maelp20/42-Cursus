/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:46:41 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/24 17:47:48 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
					cost = cost - size;
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
			(*stack_b)->cost_b = (*stack_b)->pos - size;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = tmp;
}