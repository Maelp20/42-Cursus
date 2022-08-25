/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:28:31 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/25 14:51:33 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	put_window(t_data *data, int width, int height)
{
	data->win = mlx_new_window(data->mlx, width, height + 32, "So long !");
	if (data->win == NULL)
		free(data->win);
}

int	init_img(t_data *data)
{
	int	n;

	data->background = mlx_xpm_file_to_image(data->mlx, PATH_BG, &n, &n);
	data->wall = mlx_xpm_file_to_image(data->mlx, PATH_WALL, &n, &n);
	data->coll = mlx_xpm_file_to_image(data->mlx, PATH_COLL, &n, &n);
	data->exit = mlx_xpm_file_to_image(data->mlx, PATH_EXIT, &n, &n);
	data->player = mlx_xpm_file_to_image(data->mlx, PATH_PLAYER, &n, &n);
	data->play_left = mlx_xpm_file_to_image(data->mlx, PATH_PLAY_LEFT, &n, &n);
	data->enemy = mlx_xpm_file_to_image(data->mlx, PATH_ENEMY, &n, &n);
	if (data->wall == NULL || data->coll == NULL || data->exit == NULL
		|| data->player == NULL || data->play_left == NULL
		|| data->enemy == NULL)
		return (ft_putstr_fd("Error\nFailed to load an image\n", 2), 1);
	return (0);
}

int	init_nbr(t_data *data)
{
	int	n;

	data->nbr.zero = mlx_xpm_file_to_image(data->mlx, PATH_ZERO, &n, &n);
	data->nbr.one = mlx_xpm_file_to_image(data->mlx, PATH_ONE, &n, &n);
	data->nbr.two = mlx_xpm_file_to_image(data->mlx, PATH_TWO, &n, &n);
	data->nbr.three = mlx_xpm_file_to_image(data->mlx, PATH_THREE, &n, &n);
	data->nbr.four = mlx_xpm_file_to_image(data->mlx, PATH_FOUR, &n, &n);
	data->nbr.five = mlx_xpm_file_to_image(data->mlx, PATH_FIVE, &n, &n);
	data->nbr.six = mlx_xpm_file_to_image(data->mlx, PATH_SIX, &n, &n);
	data->nbr.seven = mlx_xpm_file_to_image(data->mlx, PATH_SEVEN, &n, &n);
	data->nbr.eight = mlx_xpm_file_to_image(data->mlx, PATH_EIGHT, &n, &n);
	data->nbr.nine = mlx_xpm_file_to_image(data->mlx, PATH_NINE, &n, &n);
	if (!data->nbr.zero || !data->nbr.one || !data->nbr.two || !data->nbr.three
		|| !data->nbr.four || !data->nbr.five || !data->nbr.six
		|| !data->nbr.seven || !data->nbr.eight || !data->nbr.nine)
		return (ft_putstr_fd("Error\nFailed to load an image\n", 2), 1);
	return (0);
}

void	put_img(t_data *data, char type, int x, int y)
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
	else if (type == 'M')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy, x, y);
}

void	put_elements(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[0][j])
	{
		put_background(data, j);
		j++;
	}
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_img(data, data->map[i][j], j * 32, (i + 1) * 32);
			j++;
		}
		i++;
	}
}
