/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:28:31 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/07 18:39:06 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_img(t_data *data, char type, int x, int y)
{
	if (type == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, x, y);
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