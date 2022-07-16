/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:25:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/16 16:47:59 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    choose_instructions(t_list **stack_a)
{
    if ((*stack_a)->content > (*stack_a)->next->next->next->content)
        ft_rotate(stack_a, 'a');
    else if ((*stack_a)->content > (*stack_a)->next->next->content)
    {
        ft_rrotate(stack_a, 'a');
        ft_swap(stack_a, 'a');
        ft_rotate(stack_a, 'a');
        ft_rotate(stack_a, 'a');
    }
    else if ((*stack_a)->content > (*stack_a)->next->content)
        ft_swap(stack_a, 'a');
}

void    second_instructions(t_list **stack_a)
{
    if ((*stack_a)->content > (*stack_a)->next->next->next->next->content)
        ft_rotate(stack_a, 'a');
    else if ((*stack_a)->content > (*stack_a)->next->next->next->content)
    {
        ft_rrotate(stack_a, 'a');
        ft_swap(stack_a, 'a');
        ft_rotate(stack_a, 'a');
        ft_rotate(stack_a, 'a');
    }
    else if ((*stack_a)->content > (*stack_a)->next->next->content 
            && (*stack_a)->content < (*stack_a)->next->next->next->content)
    {
        ft_swap(stack_a, 'a');
        ft_rotate(stack_a, 'a');
        ft_swap(stack_a, 'a');
        ft_rrotate(stack_a, 'a');
    }
    else if ((*stack_a)->content > (*stack_a)->next->content)
        ft_swap(stack_a, 'a');
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
    t_list	**itera;
	t_list	*min;
	t_list	*max;

	// ne fonctionne pas
    itera = stack_a;
    min = find_min(*itera);
    max = find_max(*itera);
    if (ft_lstsize(*stack_a) > 4)
        ft_push(stack_a, stack_b, 'b');
    ft_push(stack_a, stack_b, 'b');
    sort_3(stack_a);
    ft_push(stack_a, stack_b, 'a');
    choose_instructions(stack_a);
    if (*stack_b)
    {
        ft_push(stack_a, stack_b, 'a');
        second_instructions(stack_a);
    }
}

// void    sort_5(t_list **stack_a, t_list    **stack_b)
// {
//     if ((*stack_a)->position != 1 && ft_is_min(stack_a) < 4)
//         while ((*stack_a)->position != 1)
//             ft_ra(stack_a);
//     else
//         while ((*stack_a)->position != 1)
//             ft_rra(stack_a);
//     (*stack_a)->position = 0;
//     if (ft_lstsize(*stack_a) > 4)
//         ft_pb(stack_a, stack_b);
//     if ((*stack_a)->position != 1 && ft_is_min(stack_a) < 4)
//         while ((*stack_a)->position != 1)
//             ft_ra(stack_a);
//     else
//         while ((*stack_a)->position != 1)
//             ft_rra(stack_a);
//     (*stack_a)->position = 0;
//     if (ft_lstsize(*stack_a) > 3)
//         ft_pb(stack_a, stack_b);
//     sort_3(stack_a);
//     ft_pa(stack_b, stack_a);
//     ft_pa(stack_b, stack_a);
// }