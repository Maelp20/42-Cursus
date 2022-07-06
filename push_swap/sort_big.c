/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:25:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/06 13:09:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void printlist(t_list *lst, char id);

static int sorted(int *tab, int size)
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
	while (sorted(tab, size))
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

static int	find_median(t_list *lst)
{
	int	median;
	int	i;
	int	*buff;
	t_list	*tmp;

	buff = (int *)malloc(sizeof(int) * ft_lstsize(lst));
	i = 0;
	tmp = lst;
	while (tmp)
	{
		buff[i] = tmp->content;
		tmp = tmp ->next;
		i++;
	}
	sort_int_tab(buff, i);
	median = buff[i / 2];
	printf ("MEDIAN = %d\n", median);
	free(buff);
	return (median);
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
    t_list *move;
	t_list	*head_chunk;
	int		median;
	int		size;

	while (*stack_a)
	{
		median = find_median(*stack_a);
		move = *stack_a;
		size = ft_lstsize(*stack_a);
    	while(size > 0)
		{
			if (move->content < median)
				ft_push(stack_a, stack_b, 'b');
			else
				ft_rotate(stack_a);
			move = *stack_a;
			size--;
		}
		head_chunk = 
	}
	// repeter jusqu'a ce que stack_a soit vide ou reste 2 elements.
	// si besoin mettre les 2 elements restants dans l'ordre.
	// a chaque repetition de la fonction, traquer combien d'elements sont dans stack_b,
	// pour les repartir par Chunck.
	// ensuite, pour chaque Chunk de stack_b, repeter l'operation a l'inverse : 
	// trouver median, push vers a les nombres qui sont au dessus de median.
}