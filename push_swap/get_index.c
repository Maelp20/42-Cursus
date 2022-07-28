/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:46:41 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/28 14:55:39 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_index(t_list **stack_a, int *buff, int size)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	while (*stack_a)
	{
		i = 0;
		while (i < size)
		{
			if ((*stack_a)->content == buff[i])
				(*stack_a)->index = i + 1;
			i++;
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
}

void	get_index(t_list **stack_a)
{
	int		i;
	int		size;
	int		*buff;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	buff = (int *)malloc(sizeof(int) * size);
	while (size > 0)
	{
		buff[i] = tmp->content;
		tmp = tmp->next;
		i++;
		size --;
	}
	sort_int_tab(buff, i);
	find_index(stack_a, buff, i);
	free(buff);
}
