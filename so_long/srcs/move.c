/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:25:22 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/08 16:34:17 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_data *data, int x, int y)
{
	if (data->map[x - 1][y] == '0')
	{
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'P';
		data->counter++;
	}
	else if (data->map[x - 1][y] == 'C')
	{
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'P';
		data->counter++;
		data->nbr_coll--;
	}
	else if (data->map[x - 1][y] == 'E' && data->nbr_coll == 0)
	{
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'P';
		data->counter++;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	ft_printf("MOVES : %d\n", data->counter);
	if (data->win_ptr != NULL)
		put_elements(data);
}

void	move_down(t_data *data, int x, int y)
{
	if (data->map[x + 1][y] == '0')
	{
		data->map[x][y] = '0';
		data->map[x + 1][y] = 'P';
		data->counter++;
	}
	else if (data->map[x + 1][y] == 'C')
	{
		data->map[x][y] = '0';
		data->map[x + 1][y] = 'P';
		data->counter++;
		data->nbr_coll--;
	}
	else if (data->map[x + 1][y] == 'E' && data->nbr_coll == 0)
	{
		data->map[x][y] = '0';
		data->map[x + 1][y] = 'P';
		data->counter++;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	ft_printf("MOVES : %d\n", data->counter);
	if (data->win_ptr != NULL)
		put_elements(data);
}

void	move_left(t_data *data, int x, int y)
{
	if (data->map[x][y - 1] == '0')
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'P';
		data->counter++;
	}
	else if (data->map[x][y - 1] == 'C')
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'P';
		data->counter++;
		data->nbr_coll--;
	}
	else if (data->map[x][y - 1] == 'E' && data->nbr_coll == 0)
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'P';
		data->counter++;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	ft_printf("MOVES : %d\n", data->counter);
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
	ft_printf("MOVES : %d\n", data->counter);
	if (data->win_ptr != NULL)
		put_elements(data);
}