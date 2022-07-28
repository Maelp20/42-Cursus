/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:31:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/28 14:31:51 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void printlist(t_list *lst, char id)
{
    if (lst == NULL)
    {
       exit(EXIT_FAILURE) ;
    }

    t_list	*print;

	print = lst;

	if (id == 'a')
		printf("Stack a : \n");
	else if (id == 'b')
		printf("Stack b : \n");
	else
		printf("Stack : \n");
    while (print)
    {
        printf("content = %d /", print->content);
		printf("index = %d /", print->index);
		printf("pos = %d /", print->pos);
		printf("target_pos = %d /", print->target_pos);
		printf("cost_a = %d /", print->cost_a);
		printf("cost_b = %d \n", print->cost_b);
        print = print->next;
    }
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (parse(&stack_a, ac, av))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (ft_lstsize(stack_a) < 2)
		return (0);
	else if (ft_lstsize(stack_a) == 2)
	{
		if (!lst_sorted(stack_a))
			ft_swap(&stack_a, 'a');	
	}
	else if (ft_lstsize(stack_a) == 3)
	{
		if (!lst_sorted(stack_a))
			sort_3(&stack_a, 'a');		
	}
	else
	{
		get_index(&stack_a);
		if (ft_lstsize(stack_a) <= 5)
			pre_sort5(&stack_a, &stack_b);
		else
			pre_sort(&stack_a, &stack_b);
		sort_big(&stack_a, &stack_b);
		finish_sorting(&stack_a);
	}
	// printlist(stack_a, 'a');
	// printlist(stack_b, 'b');
	return (0);
}