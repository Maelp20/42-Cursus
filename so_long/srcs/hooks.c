/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:38:00 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/22 19:00:19 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_no_event(void)
{
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = 0;
	return (0);
}

void	find_player(t_data *data, int *x, int *y)
{
	while (data->map[*x])
	{
		*y = 0;
		while (data->map[*x][*y])
		{
			if (data->map[*x][*y] == 'P' || data->map[*x][*y] == 'L')
				return ;
			(*y)++;
		}
		(*x)++;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	else if (keysym == XK_w || keysym == XK_s
		|| keysym == XK_a || keysym == XK_d)
		move(data, keysym);
	return (0);
}

void	hooks(t_data *data)
{
	if (data->win == NULL)
		return ;
	mlx_loop_hook(data->mlx, &handle_no_event, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win, ClientMessage, NoEventMask, &close_window, data);
}
