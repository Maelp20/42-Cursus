/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:38:00 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/08 16:33:36 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_no_event(void)
{
	return (0);
}

void	find_player(t_data *data, int *x, int *y)
{
	while (data->map[*x])
	{
		*y = 0;
		while (data->map[*x][*y])
		{
			if (data->map[*x][*y] == 'P')
				return ;
			(*y)++;
		}
		(*x)++;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	find_player(data, &x, &y);
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	else if (keysym == XK_w)
		move_up(data, x, y);
	else if (keysym == XK_s)
		move_down(data, x, y);
	else if (keysym == XK_a)
		move_left(data, x, y);
	else if (keysym == XK_d)
		move_right(data, x, y);
	return (0);
}

// int	handle_keyrelease(int keysym)
// {
// 	return (0);
// }

void	hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	// mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, data);
}