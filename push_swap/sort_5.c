/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:25:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/06 10:15:33 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list	**itera;
	t_list	*min;
	t_list	*max;
    int     cmp;

	itera = stack_a;
	min = find_min(*itera);
	max = find_max(*itera);
    ft_push(stack_a, stack_b, 'b');
    ft_push(stack_a, stack_b, 'b');
    sort_3(stack_a);
    while (lst_sorted(*stack_a))
    {
        if (*stack_b == max || *stack_b == min)
        {
            ft_push(stack_a, stack_b, 'a');
            if (*stack_b == max)
                ft_rotate(stack_a);
        }
        else
        {
            cmp = -1;
             while(*stack_b > *stack_a)
             {
                ft_rotate(stack_a);
                cmp++;
             }
            ft_push(stack_a, stack_b, 'a');
            while (--cmp > 0)
                ft_rrotate(stack_a);
        }
    }
}