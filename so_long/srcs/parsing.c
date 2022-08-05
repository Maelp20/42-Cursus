/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:28:31 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/05 18:58:43 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
void	put_window(t_data *data, int width, int height)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "So lonnnnng !");
	if (data->win_ptr == NULL)
		free(data->win_ptr);
}

void get_map_size(t_data *data)
{
	int	fd;
	char *str;
	int	nb_lines;

	fd = open("./maps/map1.ber", O_RDONLY);
	str = get_next_line(fd);
	data->win_width = ft_strlen(str) * 32;
	nb_lines = 0;
	while (str)
	{
		nb_lines++;
		free(str);
		str = get_next_line(fd);
	}
	data->win_height = nb_lines * 32;
}