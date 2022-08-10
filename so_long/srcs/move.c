/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:25:22 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/10 16:42:21 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	else if (data->map[x - 1][y] == 'E' && data->nbr_coll == 0)
	{
		data->map[x - 1][y] = data->map[x][y];
		data->map[x][y] = '0';
		data->counter++;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (data->win_ptr != NULL)
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
	else if (data->map[x + 1][y] == 'E' && data->nbr_coll == 0)
	{
		data->map[x + 1][y] = data->map[x][y];
		data->map[x][y] = '0';
		data->counter++;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (data->win_ptr != NULL)
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
	else if (data->map[x][y - 1] == 'E' && data->nbr_coll == 0)
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'L';
		data->counter++;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (data->win_ptr != NULL)
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
	else if (data->map[x][y + 1] == 'E' && data->nbr_coll == 0)
	{
		data->map[x][y] = '0';
		data->map[x][y + 1] = 'P';
		data->counter++;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (data->win_ptr != NULL)
		put_elements(data);
}

void	move(t_data *data, int x, int y, int keysym, int tmp)
{
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