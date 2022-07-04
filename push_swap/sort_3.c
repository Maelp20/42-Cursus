/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:25:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/04 13:16:12 by mpignet          ###   ########.fr       */
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

void	sort_3(t_list **lst)
{
	t_list *tmp;
	t_list **itera;

	itera = lst;
	
}