/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:31:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/24 17:24:38 by mpignet          ###   ########.fr       */
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

// void printchunk(t_list *lst, char id, int chunk_id)
// {
//     if (lst == NULL)
//     {
//        exit(EXIT_FAILURE) ;
//     }

//     t_list	*print;

// 	print = lst;

// 	if (id == 'a')
// 		printf("Stack a : \n");
// 	else if (id == 'b')
// 		printf("Stack b : \n");
// 	else
// 		printf("Stack : \n");
//     while (print && print->chunk_id == chunk_id)
//     {
//         printf("%d (%d) // ", print->content, print->chunk_id);
//         print = print->next;
//     }
// }

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
	get_index(&stack_a);
	pre_sort(&stack_a, &stack_b);
	// ft_push(&stack_a, &stack_b, 'b');
	// ft_push(&stack_a, &stack_b, 'b');
	// ft_push(&stack_a, &stack_b, 'b');
	// ft_push(&stack_a, &stack_b, 'b');
	// ft_push(&stack_a, &stack_b, 'b');
	// ft_push(&stack_a, &stack_b, 'b');
	find_positions(&stack_a, &stack_b);
	find_target_pos(&stack_a, &stack_b);
	get_cost_b(&stack_b);
	get_cost_a(&stack_a, &stack_b);
	printlist(stack_a, 'a');
	printlist(stack_b, 'b');
	return (0);
}

// int main(int ac, char **av)
// {
//     t_list *lsta;
//     t_list *lstb;

//     int i;
//     i = 0;
//     int *n;
//     n = malloc(sizeof(n) * ac);

//     lsta = NULL;
//     while (av[i + 1])
//     {
//         n[i] = ft_atoi(av[i + 1]);
//         ft_lstadd_back(&lsta, ft_lstnew(&n[i]));
//         i++;
//     }

//     sa(lsta);
//     t_list *tmp = lsta;
//     while (tmp)
//     {
//         printf("%d\n", *(int *)(tmp->content));
//         tmp = tmp->next;
//     }    
// }