/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:38:59 by mpignet           #+#    #+#             */
/*   Updated: 2022/06/20 16:29:06 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list *a)
{
	t_list *tmp;

	tmp = a->content;
	a->content = a->next->content;
	a = a->next;
	a->content = tmp;
	write (1, "sa\n", 3);
}

void	ft_sb(t_list *b)
{
	t_list *tmp;

	tmp = b->content;
	b->content = b->next->content;
	b = b->next;
	b->content = tmp;
	write (1, "sb\n", 3);
}

void	ft_ss(t_list *a, t_list *b)
{
	ft_sa(a);
	ft_sb(b);
	write (1, "ss\n", 3);
}


void	ft_pa(t_list **a, t_list *b)
{
	ft_lstadd_front(&a, b);
	b->next = b;
	write (1, "pb\n", 3);
}

// void	ft_pa(t_list *a, t_list *b)
// {
// 	t_list *tmp;
	
// 	if (!b)
// 		return ;
// 	tmp = a;
// 	a->content = b->content;
// 	b = b->next;
// 	a->next = tmp;
// 	write (1, "pa\n", 3);
// }

void	ft_pb(t_list *a, t_list **b)
{
	ft_lstadd_front(b, a);
	a->next = a;
	write (1, "pb\n", 3);
}

// void	ft_pb(t_list *a, t_list *b)
// {
// 	t_list *tmp;
	
// 	if (!a)
// 		return ;
// 	tmp = b;
// 	b->content = a->content;
// 	a = a->next;
// 	b->next = tmp;
// 	write (1, "pb\n", 3);
// }

void	ft_ra(t_list *a)
{
	t_list *first;

	first = a;
	first->next = NULL;
	while (a->next)
	{
		a->content = a->next->content;
		a = a->next;
	}
	a = first;
	write (1, "ra\n", 3);
}

void	ft_rb(t_list *b)
{
	t_list *first;

	first = b;
	first->next = NULL;
	while (b->next)
	{
		b->content = b->next->content;
		b = b->next;
	}
	b = first;
	write (1, "rb\n", 3);
}

void	ft_rr(t_list *a, t_list *b)
{
	ft_ra(a);
	ft_rb(b);
	write (1, "rr\n", 3);
}

// TEST MAIN //

// #include <stdio.h>

// void printlist(t_list *lst)
// {
//     if (lst == NULL)
//     {
//         exit(EXIT_FAILURE);
//     }

//     t_list	*print;

// 	print = lst;

// 	printf("a : \n");
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
// 	t_list *number;
	
// 	number = ft_lstnew((void *)3);
// 	a = ft_lstnew(number->content);
// 	number->content = (void *)2;
// 	ft_lstadd_front(&a, number);
	
// 	ft_sa(a); // OK
// 	ft_ra(a); // PAS OK
	
// 	printlist(a);
// }