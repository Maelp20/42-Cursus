/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:07:41 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/24 15:30:58 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// int	moves_cost(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp;
// 	int	cost;
// 	int	min;
	
// 	cost = 0;
// 	tmp = *stack_a;
// 	while (*stack_a)
// 	{
// 		min = find_min(tmp)->content;
// 		if((*stack_b)->content < tmp->content 
// 			&& ((*stack_b)->content > ft_lstlast(tmp)->content))
// 			break ;
// 		else if ((*stack_b)->content < min)
// 		{
// 			while (tmp->content != min)
// 				tmp = tmp->next;
// 			break ;
// 		}
// 		tmp = tmp->next;
// 		cost++;
// 	}
// 	if(cost <= (ft_lstsize(*stack_a) / 2))
// 		return (1);
// 	return(0);
// }

// void	exec_moves(t_list **stack_a, t_list **stack_b)
// {
// 	int	go_rotate;
	
// 	go_rotate = moves_cost(stack_a, stack_b);
// 	if((*stack_b)->content < (*stack_a)->content 
// 	&& ((*stack_b)->content > ft_lstlast(*stack_a)->content))
// 	{
// 		ft_push(stack_a, stack_b, 'a');
// 		return ;	
// 	}
// 	else if ((*stack_b)->content < find_min(*stack_a)->content)
// 		if ((*stack_a)->content == find_min(*stack_a)->content)
// 	{
// 		ft_push(stack_a, stack_b, 'a');
// 		return ;
// 	}
// 	if (go_rotate == 1)
// 		ft_rotate(stack_a, 'a');
// 	else
// 		ft_rrotate(stack_a, 'a');
// }

// void	insert_sort(t_list **stack_a, t_list  **stack_b)
// {
// 	int		loops;

// 	loops = 0;
// 	while (*stack_b)
// 	{
// 		if ((*stack_b)->content > ft_lstlast(*stack_b)->content)
// 			ft_rrotate(stack_b, 'b');
// 		exec_moves(stack_a, stack_b);
// 		loops++;
// 	}
// 	while (!lst_sorted(*stack_a))
// 		ft_rotate(stack_a, 'a');
// }

// void	presort_in_b(t_list **stack_a, t_list **stack_b)
// {
// 	// printf ("PRESORT IN B\n");
// 	int		median;
// 	int		size;

// 	size = ft_lstsize(*stack_a);
// 	median = find_median(*stack_a, 0);
// 	while(size > 3)
// 	{
// 		if ((*stack_a)->content < median)
// 			ft_push(stack_a, stack_b, 'b');
// 		else
// 			ft_rotate(stack_a, 'a');
// 		size--;
// 	}
// 	return ;
// }

// void	pre_sort(t_list **stack_a, t_list **stack_b)
// {
// 	// printf ("PRE SORT\n");
// 	if (!*stack_b && lst_sorted(*stack_a))
// 		return ;
// 	if (ft_lstsize(*stack_a) == 3)
// 	{
// 		if (!lst_sorted(*stack_a))
// 			sort_3(stack_a, 'a');
// 		insert_sort(stack_a, stack_b);
// 	}
// 	else if (ft_lstsize(*stack_a) == 2)
// 	{
// 		if (!lst_sorted(*stack_a))
// 			ft_swap(stack_a, 'a');
// 		insert_sort(stack_a, stack_b);
// 	}
// 	else if (ft_lstsize(*stack_a) == 1)
// 		insert_sort(stack_a, stack_b);
// 	else
// 	{
// 		presort_in_b(stack_a, stack_b);
// 		pre_sort(stack_a, stack_b);
// 	}
// }