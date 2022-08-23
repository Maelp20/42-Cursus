/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_score_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:01:59 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/23 15:39:37 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	put_background(t_data *data, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, data->background, j * 32, 0);
}

void	put_score(t_data *data, void *img, int pos)
{
	mlx_put_image_to_window(data->mlx, data->win, img, pos * 18, 0);
}

void	display_nbr(t_data *data, char nbr, int pos)
{
	if (nbr == '0')
		put_score(data, data->nbr.zero, pos);
	if (nbr == '1')
		put_score(data, data->nbr.one, pos);
	if (nbr == '2')
		put_score(data, data->nbr.two, pos);
	if (nbr == '3')
		put_score(data, data->nbr.three, pos);
	if (nbr == '4')
		put_score(data, data->nbr.four, pos);
	if (nbr == '5')
		put_score(data, data->nbr.five, pos);
	if (nbr == '6')
		put_score(data, data->nbr.six, pos);
	if (nbr == '7')
		put_score(data, data->nbr.seven, pos);
	if (nbr == '8')
		put_score(data, data->nbr.eight, pos);
	if (nbr == '9')
		put_score(data, data->nbr.nine, pos);
}

void	display_score(t_data *data)
{
	char	*nbr;
	int		x;

	nbr = ft_itoa(data->counter);
	x = 0;
	while (nbr[x])
	{
		display_nbr(data, nbr[x], x);
		x++;
	}
	free(nbr);
}
