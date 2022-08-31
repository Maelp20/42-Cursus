/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:28:31 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/31 15:20:45 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	init_img(t_data *data)
{
	int	n;

	data->background = mlx_xpm_file_to_image(data->mlx, PATH_BG, &n, &n);
	data->wall = mlx_xpm_file_to_image(data->mlx, PATH_WALL, &n, &n);
	data->coll = mlx_xpm_file_to_image(data->mlx, PATH_COLL, &n, &n);
	data->exit = mlx_xpm_file_to_image(data->mlx, PATH_EXIT, &n, &n);
	data->player = mlx_xpm_file_to_image(data->mlx, PATH_PLAYER, &n, &n);
	data->play_left = mlx_xpm_file_to_image(data->mlx, PATH_PLAY_LEFT, &n, &n);
	if (data->wall == NULL || data->coll == NULL || data->exit == NULL
		|| data->player == NULL || data->play_left == NULL)
		return (ft_putstr_fd("Error\nFailed to load an image\n", 2), 1);
	return (0);
}

static void	put_img(t_data *data, char type, int x, int y)
{
	if (type == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->background, x, y);
	else if (type == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
	else if (type == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->coll, x, y);
	else if (type == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player, x, y);
	else if (type == 'L')
		mlx_put_image_to_window(data->mlx, data->win, data->play_left, x, y);
}

void	put_elements(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_img(data, data->map[i][j], j * 32, i * 32);
			j++;
		}
		i++;
	}
}
