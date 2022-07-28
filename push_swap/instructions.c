/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:38:59 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/28 14:54:10 by mpignet          ###   ########.fr       */
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
	t_list	*tmp2;

	tmp = (*lst)->next;
	tmp2 = ft_lstlast(*lst);
	(*lst)->next = NULL;
	tmp2->next = *lst;
	*lst = tmp;
	if (id == 'a')
		write (1, "ra\n", 3);
	else if (id == 'b')
		write (1, "rb\n", 3);
	else if (id == 'd')
		write (1, "rr\n", 3);
}

void	ft_rrotate(t_list **lst, char id)
{
	t_list	*tmp;
	t_list	*tmp2;

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
	else if (id == 'd')
		write (1, "rrr\n", 4);
}

void	ft_double(t_list **stack_a, t_list **stack_b, int id)
{
	if (id == 0)
	{
		ft_rotate(stack_a, 'i');
		ft_rotate(stack_b, 'd');
	}
	else if (id == 1)
	{
		ft_rrotate(stack_a, 'i');
		ft_rrotate(stack_b, 'd');
	}
}
