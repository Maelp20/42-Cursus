/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:25:22 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/23 15:29:14 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	move_up(t_data *data, int x, int y)
{
	if (data->map[x - 1][y] == '0')
	{
		data->map[x - 1][y] = data->map[x][y];
		data->map[x][y] = '0';
		data->counter++;
	}
	else if (data->map[x - 1][y] == 'C')
	{
		data->map[x - 1][y] = data->map[x][y];
		data->map[x][y] = '0';
		data->counter++;
		data->nbr_coll--;
	}
	else if (data->map[x - 1][y] == 'M'
		|| (data->map[x - 1][y] == 'E' && data->nbr_coll == 0))
	{
		data->map[x - 1][y] = data->map[x][y];
		data->map[x][y] = '0';
		data->counter++;
		close_window(data);
	}
	if (data->win != NULL)
		put_elements(data);
}

void	move_down(t_data *data, int x, int y)
{
	if (data->map[x + 1][y] == '0')
	{
		data->map[x + 1][y] = data->map[x][y];
		data->map[x][y] = '0';
		data->counter++;
	}
	else if (data->map[x + 1][y] == 'C')
	{
		data->map[x + 1][y] = data->map[x][y];
		data->map[x][y] = '0';
		data->counter++;
		data->nbr_coll--;
	}
	else if (data->map[x + 1][y] == 'M'
		|| (data->map[x + 1][y] == 'E' && data->nbr_coll == 0))
	{
		data->map[x + 1][y] = data->map[x][y];
		data->map[x][y] = '0';
		data->counter++;
		close_window(data);
	}
	if (data->win != NULL)
		put_elements(data);
}

void	move_left(t_data *data, int x, int y)
{
	if (data->map[x][y - 1] == '0')
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'L';
		data->counter++;
	}
	else if (data->map[x][y - 1] == 'C')
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'L';
		data->counter++;
		data->nbr_coll--;
	}
	else if (data->map[x][y - 1] == 'M'
		|| (data->map[x][y - 1] == 'E' && data->nbr_coll == 0))
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'L';
		data->counter++;
		close_window(data);
	}
	if (data->win != NULL)
		put_elements(data);
}

void	move_right(t_data *data, int x, int y)
{
	if (data->map[x][y + 1] == '0')
	{
		data->map[x][y] = '0';
		data->map[x][y + 1] = 'P';
		data->counter++;
	}
	else if (data->map[x][y + 1] == 'C')
	{
		data->map[x][y] = '0';
		data->map[x][y + 1] = 'P';
		data->counter++;
		data->nbr_coll--;
	}
	else if (data->map[x][y + 1] == 'M'
		|| (data->map[x][y + 1] == 'E' && data->nbr_coll == 0))
	{
		data->map[x][y] = '0';
		data->map[x][y + 1] = 'P';
		data->counter++;
		close_window(data);
	}
	if (data->win != NULL)
		put_elements(data);
}

void	move(t_data *data, int keysym)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	find_player(data, &x, &y);
	if (data->win != NULL)
		put_elements(data);
	if (keysym == XK_w)
		move_up(data, x, y);
	else if (keysym == XK_s)
		move_down(data, x, y);
	else if (keysym == XK_a)
		move_left(data, x, y);
	else if (keysym == XK_d)
		move_right(data, x, y);
	if (data->win != NULL)
		display_score(data);
}
