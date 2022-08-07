/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:25:22 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/07 19:39:25 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_img(t_data *data)
{
	int	n;
	
	data->background = mlx_xpm_file_to_image(data->mlx_ptr, PATH_BG, &n, &n);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, PATH_WALL, &n, &n);
	data->coll = mlx_xpm_file_to_image(data->mlx_ptr, PATH_COLL, &n, &n);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, PATH_EXIT, &n, &n);
	if (data->wall == NULL || data->coll == NULL)
		ft_putstr_fd("Error\nFailed to load an image\n", 2);
}