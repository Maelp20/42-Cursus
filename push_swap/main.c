/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:31:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/01 17:16:06 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void printlist(t_list *lst, char id)
{
    if (lst == NULL)
    {
       exit(EXIT_FAILURE) ;
    }

    t_list	*print;

	print = lst;

	if (id == 'a')
		IMPRIMER("Stack a : \n");
	else if (id == 'b')
		IMPRIMER("Stack b : \n");
	else
		IMPRIMER("Stack : \n");
    while (print)
    {
        IMPRIMER("content = %d /", print->content);
		IMPRIMER("index = %d /", print->index);
		IMPRIMER("pos = %d /", print->pos);
		IMPRIMER("target_pos = %d /", print->target_pos);
		IMPRIMER("cost_a = %d /", print->cost_a);
		IMPRIMER("cost_b = %d \n", print->cost_b);
        print = print->next;
    }
}
*/

static void	begin(t_list **stack_a, t_list **stack_b)
{
	get_index(stack_a);
	if (ft_lstsize(*stack_a) <= 5)
		pre_sort5(stack_a, stack_b);
	else
		pre_sort(stack_a, stack_b);
	sort_big(stack_a, stack_b);
	finish_sorting(stack_a);
}

static void	clear_list(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(temp);
		temp = *lst;
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
		clear_list(&stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_lstsize(stack_a) < 2)
		return (0);
	else if (ft_lstsize(stack_a) == 2)
		while (!lst_sorted(stack_a))
			ft_swap(&stack_a, 'a');
	else if (ft_lstsize(stack_a) == 3)
		while (!lst_sorted(stack_a))
			sort_3(&stack_a, 'a');
	else
		begin(&stack_a, &stack_b);
	clear_list(&stack_a);
	return (0);
}
