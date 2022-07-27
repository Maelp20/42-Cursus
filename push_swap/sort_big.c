/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:55:21 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/24 18:44:38 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	cheapest_to_move(t_list **stack_b)
{
	int cost_min;
	int	cost_a;
	int	cost_b;
	t_list *tmp;
	t_list *tmp2;

	if (ft_lstsize(*stack_b) == 1)
		return ((*stack_b)->index);
	tmp = *stack_b;
	tmp2 = *stack_b;
	cost_min = 2147483647;
	while (tmp)
	{
		cost_a  = tmp->cost_a;
		cost_b  = tmp->cost_b;
		if (cost_a < 0)
			cost_a = - cost_a;
		if (cost_b < 0)
			cost_b = - cost_b;
		if ((cost_a + cost_b) < cost_min)
			cost_min = cost_a + cost_b;
		tmp = tmp->next;
	}
	while (tmp2)
	{
		cost_a  = tmp2->cost_a;
		cost_b  = tmp2->cost_b;
		if (cost_a < 0)
			cost_a = - cost_a;
		if (cost_b < 0)
			cost_b = - cost_b;
		if ((cost_a + cost_b) == cost_min)
			break ;
		tmp2 = tmp2->next;
	}
	return (tmp2->index);
}

void	do_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0)
	{
		cost_a = -cost_a;
		if (cost_b < 0)
		{
			cost_b = -cost_b;
			while (cost_a > 0 && cost_b > 0)
			{
				ft_double(stack_a, stack_b, 1);
				cost_a--;
				cost_b--;
			}
			while (cost_b > 0)
			{
				ft_rrotate(stack_b, 'b');
				cost_b--;
			}
		}
		else
			while (cost_b > 0)
			{
				ft_rotate(stack_b, 'b');
				cost_b--;
			}
		while (cost_a > 0)
		{
			ft_rrotate(stack_a, 'a');
			cost_a--;
		}
	}
	else
	{
		if (cost_b < 0)
		{
			cost_b = -cost_b;
			while (cost_b > 0)
			{
				ft_rrotate(stack_b, 'b');
				cost_b--;
			}
		}
		else
		{
			while (cost_a > 0 && cost_b > 0)
			{
				ft_double(stack_a, stack_b, 0);
				cost_a--;
				cost_b--;
			}
			while (cost_b > 0)
			{
				ft_rotate(stack_b, 'b');
				cost_b--;
			}
		}
		while (cost_a > 0)
		{
			ft_rotate(stack_a, 'a');
			cost_a--;
		}
	}
	ft_push(stack_a, stack_b, 'a');
}

void	finish_sorting(t_list **stack_a)
{
	t_list *tmp;

	tmp = *stack_a;
	while (tmp->index != 1)
		tmp = tmp->next;
	if (tmp->pos <= ft_lstsize(*stack_a) / 2)
		while (!lst_sorted(*stack_a))
			ft_rotate(stack_a, 'a');
	else
		while (!lst_sorted(*stack_a))
			ft_rrotate(stack_a, 'a');
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	int		index_cheapest;

	if (!*stack_b)
		return ;
	find_positions(stack_a, stack_b);
	find_target_pos(stack_a, stack_b);
	get_cost_b(stack_b);
	get_cost_a(stack_a, stack_b);
	index_cheapest = cheapest_to_move(stack_b);
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index == index_cheapest)
			break ;
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, tmp->cost_a, tmp->cost_b);
	sort_big(stack_a, stack_b);
}