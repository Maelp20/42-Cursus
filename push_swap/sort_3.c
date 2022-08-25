/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:25:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/25 15:57:42 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *itera)
{
	int		tmp;
	t_list	*min;

	tmp = itera->content;
	min = itera;
	while (itera)
	{
		if (itera->content < tmp)
		{
			tmp = itera->content;
			min = itera;
		}
		itera = itera->next;
	}
	return (min);
}

t_list	*find_max(t_list *itera)
{
	int		tmp;
	t_list	*max;

	tmp = itera->content;
	max = itera;
	while (itera)
	{
		if (itera->content > tmp)
		{
			tmp = itera->content;
			max = itera;
		}
		itera = itera->next;
	}
	return (max);
}

void	sort_3(t_list **lst, char id)
{
	t_list	**itera;
	t_list	*min;
	t_list	*max;

	itera = lst;
	min = find_min(*itera);
	max = find_max(*itera);
	if ((*itera)->next == min && (*itera)->next->next == max)
		ft_swap(lst, id);
	if ((*itera)->next->next == min && (*itera)->next == max)
		ft_rrotate(lst, id);
	if (*itera == max && (*itera)->next == min)
		ft_rotate(lst, id);
	if (*itera == min && (*itera)->next == max)
	{
		ft_rrotate(lst, id);
		ft_swap(lst, id);
	}
	if (*itera == max && (*itera)->next->next == min)
	{
		ft_rotate(lst, id);
		ft_swap(lst, id);
	}
}
