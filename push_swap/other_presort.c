/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:57:31 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/24 15:34:58 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	presort_in_b(t_list **stack_a, t_list **stack_b)
{
	// printf ("PRESORT IN B\n");
	int		median;
	int		size;

	size = ft_lstsize(*stack_a);
	median = find_median(*stack_a, 0);
	while(size > 3)
	{
		if ((*stack_a)->content < median)
			ft_push(stack_a, stack_b, 'b');
		else
			ft_rotate(stack_a, 'a');
		size--;
	}
	return ;
}

void	pre_sort(t_list **stack_a, t_list **stack_b)
{
	// printf ("PRE SORT\n");
	if (!*stack_b && lst_sorted(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 3)
	{
		if (!lst_sorted(*stack_a))
			sort_3(stack_a, 'a');
		return ;
		insert_sort(stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_a) == 2)
	{
		if (!lst_sorted(*stack_a))
			ft_swap(stack_a, 'a');
		return ;
		insert_sort(stack_a, stack_b);
	}
	// else if (ft_lstsize(*stack_a) == 1)
	// 	insert_sort(stack_a, stack_b);
	else
	{
		presort_in_b(stack_a, stack_b);
		pre_sort(stack_a, stack_b);
	}
}