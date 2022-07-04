/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:31:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/06/24 17:38:47 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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
        printf("%d\n", (int *)(print->content));
        print = print->next;
    }
    printf("%d\n", (int *)(print->content));
}

int	main(int ac, char **av)
{
	t_list	*lst;
	
	lst = (t_list *)malloc(sizeof(t_list));
	if (args_check(lst, ac, av))
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
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