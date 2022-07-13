/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:25:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/07 17:26:58 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void printlist(t_list *lst, char id);

int	lst_sorted(t_list *lst)
{
	t_list	*tmp;
	
	tmp = lst;
	while (tmp)
	{
		if (tmp > tmp->next)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	lst_inv_sorted(t_list *lst)
{
	t_list	*tmp;
	
	tmp = lst;
	while (tmp)
	{
		if (tmp < tmp->next)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int tab_sorted(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static void	sort_int_tab(int *tab, int size)
{
	int i;
	int swap;
	
	swap = 0;
	while (tab_sorted(tab, size))
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
	}
}

static int	find_median(t_list *lst, int chunk_size)
{
	int	median;
	int	i;
	int	size;
	int	*buff;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	if (chunk_size)
		size = chunk_size;
	else
		size = ft_lstsize(lst);
	buff = (int *)malloc(sizeof(int) * size);
	while (size > 0)
	{
		buff[i] = tmp->content;
		tmp = tmp ->next;
		i++;
		size --;
	}
	sort_int_tab(buff, i);
	median = buff[i / 2];
	printf ("MEDIAN = %d\n", median);
	free(buff);
	return (median);
}

int	push_to_b(t_list **stack_a, t_list **stack_b, int chunk)
{
	int		median;
	int		size;
	int		chunk_size;

	if (chunk == 1)
		return (ft_push(stack_a, stack_b, 'b'), 1);
	median = find_median(*stack_a, chunk);
	if (chunk != 0)
		size = chunk;
	else
		size = ft_lstsize(*stack_a);
	// printf ("SIZE LST B = %d\n", size);
	chunk_size = 0;
	while(size > 0)
	{
		if ((*stack_a)->content < median)
		{
			ft_push(stack_a, stack_b, 'b');
			chunk_size++;
		}
		else
			ft_rotate(stack_a);
		size--;
	}
	// printf ("CHUNK SIZE = %d\n", chunk_size);
	return (chunk_size);
	// trouver mediane
	// push les elem inferieurs a mediane dans b
	// retourner le nb d'elem qui ont ete push
}

int	push_to_a(t_list **stack_a, t_list **stack_b, int chunk)
{
	int		median;
	int		size;
	int		chunk_size;

	if (chunk == 1)
		return (ft_push(stack_a, stack_b, 'a'), 1);
	median = find_median(*stack_b, chunk);
	if (chunk != 0)
		size = chunk;
	else
		size = ft_lstsize(*stack_b);
	chunk_size = 0;
	while(size > 0)
	{
		if ((*stack_b)->content > median)
		{
			ft_push(stack_a, stack_b, 'a');
			chunk_size++;
		}
		else
			ft_rotate(stack_b);
		size--;
	}
	// printf ("CHUNK SIZE FROM B = %d\n", chunk_size);
	return (chunk_size);
	// trouver mediane
	// push les elem superieurs a mediane dans a
	// retourner le nb d'elem qui ont ete push
}

void	sort_b_to_a(t_list **stack_a, t_list **stack_b)
{
	int	chunk_size;
	printf ("SORT B TO A\n");

	// if (!lst_inv_sorted(*stack_b))
	// {
	// 	while(*stack_b)
	// 		ft_push(stack_a, stack_b, 'a');
	// }
	chunk_size = push_to_a(stack_a, stack_b, 0);
	if (ft_lstsize(*stack_b) == 2)
	{
		if (lst_inv_sorted(*stack_b))
			ft_swap(stack_b);
		ft_push(stack_a, stack_b, 'a');
		ft_push(stack_a, stack_b, 'a');
	}
	if (ft_lstsize(*stack_b) == 1)
	{
		exit(EXIT_FAILURE) ;
	}
	if (!*stack_b)
	{
		// sort_big(stack_a, stack_b);
	}
	else
		sort_b_to_a(stack_a, stack_b);
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	chunk_size;
	printf ("SORT BIG\n");
	
	if (!lst_sorted(*stack_a))
		exit(EXIT_FAILURE) ;
	chunk_size = push_to_b(stack_a, stack_b, 0);
	if (ft_lstsize(*stack_a) == 3)
	{
		if (lst_sorted(*stack_a))
			sort_3(stack_a);
		sort_b_to_a(stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_a) == 2)
	{
		if (lst_sorted(*stack_a))
			ft_swap(stack_a);
		sort_b_to_a(stack_a, stack_b);
	}
	else if (!*stack_a)
		return ;
	else
		sort_big(stack_a, stack_b);
	// envoyer dans push_to_b
	// repeter jusqu'a ce que stack_a soit vide ou reste 2 elements.
	// si besoin mettre les 2 elements restants dans l'ordre.
	// a chaque repetition de la fonction, traquer combien d'elements sont dans stack_b.
	// ensuite, pour chaque Chunk de stack_b, repeter l'operation a l'inverse : 
	// trouver median, push vers stack_a les nombres qui sont au dessus de median.
}