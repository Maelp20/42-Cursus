/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:38:59 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/17 13:13:35 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst, char id)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = *lst;
	*lst = tmp;
	if (id == 'a')
		write (1, "sa\n", 3);
	else if (id == 'b')
		write (1, "sb\n", 3);
}

void	ft_push(t_list **a, t_list **b, char id)
{
	t_list	*tmp;
	
	if (id == 'a')
	{
		if (!*b)
			return ;
	tmp = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = tmp;
	write (1, "pa\n", 3);
	}
	else if (id == 'b')
	{
		if (!*a)
			return ;
	tmp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = tmp;
	write (1, "pb\n", 3);
	}
}

void	ft_rotate(t_list **lst, char id)
{
	t_list	*tmp;
	t_list *tmp2;

	tmp = (*lst)->next;
	tmp2 = ft_lstlast(*lst);
	(*lst)->next = NULL;
	tmp2->next = *lst;
	*lst = tmp;
	if (id == 'a')
		write (1, "ra\n", 3);
	else if (id == 'b')
		write (1, "rb\n", 3);
}

void	ft_rrotate(t_list **lst, char id)
{
	t_list *tmp;
	t_list *tmp2;
	
	tmp = *lst;
	while ((*lst)->next->next)
		*lst = (*lst)->next;
	tmp2 = (*lst)->next;
	(*lst)->next = NULL;
	tmp2->next = tmp;
	*lst = tmp2;
	if (id == 'a')
		write (1, "rra\n", 4);
	else if (id == 'b')
		write (1, "rrb\n", 4);
}

// TEST MAIN //

// #include <stdio.h>

// void printlist(t_list *lst, char id)
// {
//     if (lst == NULL)
//     {
//         exit(EXIT_FAILURE);
//     }

//     t_list	*print;

// 	print = lst;

// 	printf("%c : \n", id);
//     while (print != NULL)
//     {
//         printf("%d\n", print->content);
//         print = print->next;
//     }
//     printf("NULL\n");
// }

// int	main(int ac, char **av)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	int	i;
// 	int	j;
	
// 	i = -1;
// 	a = 0;
// 	b = 0;
// 	while (++i < 7)
// 		ft_lstadd_front(&a, ft_lstnew((void *)i));
// 	j = 9;
// 	while (++j < 17)
// 		ft_lstadd_front(&b, ft_lstnew((void *)j));
	
// 	ft_rrotate(&a);
// 	printlist(a, 'a');
// 	printlist(b, 'b');
// }