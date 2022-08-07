/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:25:22 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/07 18:09:16 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_img(t_data *data)
{
	int	n;
	
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, PATH_WALL, &n, &n);
	if (data->wall == NULL)
		ft_putstr_fd("Error\nFailed to load an image\n", 2);
}