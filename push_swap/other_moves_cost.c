/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_moves_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:23:13 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/22 14:16:02 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// int	find_next(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp;
// 	int	next;
	
// 	tmp = *stack_a;
// 	next = tmp->content;
// 	while (tmp)
// 	{
// 		if (tmp->content < next && tmp->content > (*stack_b)->content)
// 			next = tmp->content;
// 		tmp = tmp->next;
// 	}
// 	printf ("Elem = %d\n", (*stack_b)->content);
// 	printf("Next = %d\n", next);
// 	return(next);
// }

// int	get_cost(t_list **stack_a, t_list **stack_b)
// {
// 	t_list *tmp;
// 	int	total_cost;
// 	int	best;
// 	int	rotates;

// 	rotates = 0;
// 	tmp = *stack_b;
// 	total_cost = 0;
// 	best = total_cost;
// 	while (tmp)
// 	{
// 		if (total_cost < best)
// 			best = total_cost;
// 		total_cost = moves_cost(stack_a, &tmp);
// 		tmp = tmp->next;
// 	}
	
// }

// int	moves_cost(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp;
// 	int	next;
// 	int	cost;
	
// 	cost = 0;
// 	next = find_next(stack_a, stack_b);
// 	tmp = *stack_a;
// 	while (tmp)
// 	{
// 		if (tmp->content == next)
// 			return (cost);
// 		tmp = tmp->next;
// 		cost++;
// 	}
// 	return(cost);
// }

// int	exec_moves(t_list **stack_a, t_list **stack_b)
// {
// 	int	go_rotate;
	
// 	go_rotate = moves_cost(stack_a, stack_b);
// 	if((*stack_b)->content < (*stack_a)->content 
// 	&& ((*stack_b)->content > ft_lstlast(*stack_a)->content))
// 	{
// 		ft_push(stack_a, stack_b, 'a');
// 		return (1) ;	
// 	}
// 	else if ((*stack_b)->content < find_min(*stack_a)->content)
// 		if ((*stack_a)->content == find_min(*stack_a)->content)
// 	{
// 		ft_push(stack_a, stack_b, 'a');
// 		return (1);
// 	}
// 	if (go_rotate == 1)
// 		ft_rotate(stack_a, 'a');
// 	else
// 		ft_rrotate(stack_a, 'a');
// 	return (0);
// }