/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:38:46 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/31 15:08:59 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	get_height(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	return (i);
}

static int	get_nb_coll(t_data *data)
{
	int	i;
	int	j;
	int	nb;
	int	player;

	i = 0;
	nb = 0;
	player = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				nb++;
			else if (data->map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (0);
	return (nb);
}

int	parsing(t_data *data, char *path)
{
	int		len;

	len = get_map_length(path);
	if (len == -1)
		return (1);
	else if (len == 0)
		return (ft_putstr_fd("Error\nMap is empty\n", 2), 1);
	data->map = malloc(sizeof(char *) * (len + 1));
	if (!data->map)
		return (1);
	if (init_map(data, path, 0))
		return (1);
	if (check_square(data) || check_exit(data) || check_walls(data))
		return (1);
	data->win_width = ft_strlen(data->map[0]) * 32;
	data->win_height = get_height(data) * 32;
	data->nbr_coll = get_nb_coll(data);
	if (data->nbr_coll == 0)
		return (ft_putstr_fd("Error\nWrong number of coll or players\n", 2), 1);
	return (0);
}
