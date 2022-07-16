/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:25:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/16 16:49:48 by mpignet          ###   ########.fr       */
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
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	lst_inv_sorted(t_list *lst)
{
	t_list	*tmp;
	
	tmp = lst;
	while (tmp)
	{
		if (tmp < tmp->next)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int tab_sorted(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	sort_int_tab(int *tab, int size)
{
	int i;
	int swap;
	
	swap = 0;
	while (!tab_sorted(tab, size))
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

int    track_chunk(t_list **lst, int chunk)
{
    t_list *temp;
    int    size;

    temp = *lst;
    size = 0;
    while (temp)
    {
        if (temp->chunk_id == chunk)
            size++;
        temp = temp->next;
    }
    return (size);
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
	// printf ("MEDIAN = %d\n", median);
	free(buff);
	return (median);
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int track_id)
{
	int		median;
	int		size;

	// printf ("PUSH TO B\n");
	size = ft_lstsize(*stack_a);
	median = find_median(*stack_a, 0);
	while(size > 0)
	{
		if ((*stack_a)->content < median)
		{
			(*stack_a)->chunk_id = track_id;
			ft_push(stack_a, stack_b, 'b');
		}
		else
			ft_rotate(stack_a, 'a');
		size--;
	}
	return ;
}

void	push_to_a(t_list **stack_a, t_list **stack_b, int track_id)
{
	int		median;
	int		chunk_size;
	int		nb_rotate;

	// printf ("PUSH TO A\n");
	chunk_size = track_chunk(stack_b, track_id);
	// printf ("Chunk size = %d\n", chunk_size);
	if (chunk_size == 0)
		return ;
	if (chunk_size == 1)
		return (ft_push(stack_a, stack_b, 'a'));
	else if (chunk_size == 2)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			ft_swap(stack_b, 'b');
		return (ft_push(stack_a, stack_b, 'a'), 
				ft_push(stack_a, stack_b, 'a'));
	}
	median = find_median(*stack_b, chunk_size);
	nb_rotate = 0;
	while(--chunk_size >= 0)
	{
		if ((*stack_b)->content > median)
			ft_push(stack_a, stack_b, 'a');
		else
		{
			ft_rotate(stack_b, 'b');
			nb_rotate++;
		}
	}
	while (--nb_rotate >= 0)
		ft_rrotate(stack_b, 'b');
	// if ((*stack_a)->content > (*stack_a)->next->content)
	// 	ft_swap(stack_a);
	push_to_a(stack_a, stack_b, track_id);
	return ;
}

void	sort_b_to_a(t_list **stack_a, t_list **stack_b, int track_id)
{
	// printf ("SORT B TO A\n");
	if (!*stack_b)
		return ;
	push_to_a(stack_a, stack_b, track_id);
	track_id--;
	sort_b_to_a(stack_a, stack_b, track_id);
}

void	sort_big(t_list **stack_a, t_list **stack_b, int track_id)
{
	// printf ("SORT BIG\n");
	track_id++;
	if (lst_sorted(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 3)
	{
		if (!lst_sorted(*stack_a))
			sort_3(stack_a, 'a');
		sort_b_to_a(stack_a, stack_b, track_id);
	}
	else if (ft_lstsize(*stack_a) == 2)
	{
		if (!lst_sorted(*stack_a))
			ft_swap(stack_a, 'a');
		sort_b_to_a(stack_a, stack_b, track_id);
	}
	else if (ft_lstsize(*stack_a) == 1)
		sort_b_to_a(stack_a, stack_b, track_id);
	else
	{
		push_to_b(stack_a, stack_b, track_id);
		sort_big(stack_a, stack_b, track_id);
	}
	// Envoyer dans push_to_b
	// Repeter jusqu'a ce que stack_a soit vide ou reste 2 ou 3 elements.
	// Si besoin mettre les 2 ou 3 elements restants dans l'ordre.
	// A chaque repetition de la fonction, iterer l'id de la chunk.
	// Ensuite, pour chaque Chunk de stack_b, repeter l'operation a l'inverse : 
	// Trouver median, push vers stack_a les nombres qui sont au dessus de median.
	// Rrb tous les nombres qui ont ete rb pour retablir le restant
	// de la chunk au top de b.
	// Continuer : trouver median, push a, rb et rrb, jusqua ce qu'il reste 2 elements
	// dans la chunk.
	// Si besoin swap ces elements, les push dans a
	// passer a la chunk suivante
}