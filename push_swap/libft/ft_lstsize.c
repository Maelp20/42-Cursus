/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:13:29 by mpignet           #+#    #+#             */
/*   Updated: 2022/05/12 12:02:16 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nb;
	t_list	*tmp;

	if (!lst)
		return (0);
	nb = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		nb++;
	}
	return (nb);
}