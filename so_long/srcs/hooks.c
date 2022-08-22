/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:38:00 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/22 17:07:58 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_no_event(void)
{
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = 0;
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
	if (data->win_ptr == NULL)
		return ;
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, ClientMessage, NoEventMask, &close_window, data);
}
