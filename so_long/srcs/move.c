/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:25:22 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/31 15:20:30 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	move_up(t_data *data, int x, int y)
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
	else if (data->map[x - 1][y] == 'E' && data->nbr_coll == 0)
	{
		data->map[x - 1][y] = data->map[x][y];
		data->map[x][y] = '0';
		data->counter++;
		close_window(data);
	}
	if (data->win != NULL)
		put_elements(data);
}

static void	move_down(t_data *data, int x, int y)
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
	else if (data->map[x + 1][y] == 'E' && data->nbr_coll == 0)
	{
		data->map[x + 1][y] = data->map[x][y];
		data->map[x][y] = '0';
		data->counter++;
		close_window(data);
	}
	if (data->win != NULL)
		put_elements(data);
}

static void	move_left(t_data *data, int x, int y)
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
	else if (data->map[x][y - 1] == 'E' && data->nbr_coll == 0)
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'L';
		data->counter++;
		close_window(data);
	}
	if (data->win != NULL)
		put_elements(data);
}

static void	move_right(t_data *data, int x, int y)
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
	else if (data->map[x][y + 1] == 'E' && data->nbr_coll == 0)
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
	int	tmp;

	x = 0;
	y = 0;
	tmp = data->counter;
	find_player(data, &x, &y);
	if (keysym == XK_w)
		move_up(data, x, y);
	else if (keysym == XK_s)
		move_down(data, x, y);
	else if (keysym == XK_a)
		move_left(data, x, y);
	else if (keysym == XK_d)
		move_right(data, x, y);
	if (data->counter != tmp)
		ft_printf("MOVES : %d\n", data->counter);
}
