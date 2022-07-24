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

int	cheapest_to_move(t_list **stack_b)
{
	int cost_min;
	t_list *tmp;
	t_list *tmp2;

	tmp = *stack_b;
	tmp2 = *stack_b;
	cost_min = 2147483647;
	while (tmp)
	{
		if (tmp->cost_a < 0)
			tmp->cost_a = - (tmp->cost_a);
		if (tmp->cost_b < 0)
			tmp->cost_b = - (tmp->cost_b);
		if ((tmp->cost_a + tmp->cost_b) < cost_min)
			cost_min = tmp->cost_a + tmp->cost_b;
		tmp = tmp->next;
	}
	while (tmp2)
	{
		if (tmp->cost_a < 0)
			tmp->cost_a = - (tmp->cost_a);
		if (tmp->cost_b < 0)
			tmp->cost_b = - (tmp->cost_b);
		if ((tmp->cost_a + tmp->cost_b) == cost_min)
			break ;
	}
	return (tmp->index);
}

void	do_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		cost_a = -cost_a + 1;
		cost_b = -cost_b + 1;
		while (--cost_a > 0 && --cost_b > 0)
			ft_double(stack_a, stack_b, 1);
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		while (--cost_a >= 0 && --cost_b >= 0)
			ft_double(stack_a, stack_b, 0);
	}
	while (--cost_a > 0)
		ft_rrotate(stack_a, 'a');
	while (--cost_b > 0)
		ft_rrotate(stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	int		index_cheapest;

	index_cheapest = cheapest_to_move(stack_b);
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index == index_cheapest)
			break ;
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, tmp->cost_a, tmp->cost_b);
}