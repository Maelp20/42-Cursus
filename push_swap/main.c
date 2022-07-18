/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:31:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/17 16:27:35 by mpignet          ###   ########.fr       */
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
        printf("%d ", print->content);
        print = print->next;
    }
}

void printchunk(t_list *lst, char id, int chunk_id)
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
    while (print && print->chunk_id == chunk_id)
    {
        printf("%d (%d) // ", print->content, print->chunk_id);
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
	// printlist(stack_a, 'a');
	// while (!lst_sorted(stack_a))
	sort_big(&stack_a, &stack_b, 0);
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