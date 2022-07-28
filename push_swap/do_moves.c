/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:22:09 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/28 16:18:15 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_neg(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		ft_double(stack_a, stack_b, 1);
		cost_a++;
		cost_b++;
	}
	while (cost_b < 0)
	{
		ft_rrotate(stack_b, 'b');
		cost_b++;
	}
	if (cost_b > 0)
	{
		while (cost_b > 0)
		{
			ft_rotate(stack_b, 'b');
			cost_b--;
		}			
	}
	while (cost_a < 0)
	{
		ft_rrotate(stack_a, 'a');
		cost_a++;
	}	
}

static void	move_pos(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	while (cost_b < 0)
	{
		ft_rrotate(stack_b, 'b');
		cost_b++;
	}
	if (cost_b > 0)
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

void	do_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0)
		move_neg(stack_a, stack_b, cost_a, cost_b);
	else
		move_pos(stack_a, stack_b, cost_a, cost_b);
	ft_push(stack_a, stack_b, 'a');
}
