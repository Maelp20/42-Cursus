/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:31:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/04 14:43:15 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

// to do : check doubles

static void printlist(t_list *lst)
{
    if (lst == NULL)
    {
        exit(EXIT_FAILURE);
    }

    t_list	*print;

	print = lst;

	printf("a : \n");
    while (print->next != NULL)
    {
        printf("%d\n", print->content);
        print = print->next;
    }
    printf("%d\n", (print->content));
}

int	main(int ac, char **av)
{
	t_list	*lst;
	t_list	*b;
	
	lst = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	if (args_check(lst, ac, av))
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	lst = lst->next;
	sort_3(&lst);
	printlist(lst);
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