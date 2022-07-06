/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:25:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/06 10:15:33 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_min(t_list *itera)
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

static t_list	*find_max(t_list *itera)
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

void	sort_3(t_list **lst)
{
	t_list	**itera;
	t_list	*min;
	t_list	*max;

	itera = lst;
	min = find_min(*itera);
	max = find_max(*itera);
	if ((*itera)->next == min && (*itera)->next->next == max)
		ft_swap(lst);
	if ((*itera)->next->next == min && (*itera)->next == max)
		ft_rrotate(lst);
	if (*itera == max && (*itera)->next == min)
		ft_rotate(lst);
	if (*itera == min && (*itera)->next == max)
	{
		ft_rrotate(lst);
		ft_swap(lst);	
	}
	if (*itera == max && (*itera)->next->next == min)
	{
		ft_rotate(lst);
		ft_swap(lst);	
	}
}