/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:38:46 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/22 17:10:16 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_height(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	return (i);
}

int	get_nb_coll(t_data *data)
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
	int		fd;
	char	*buff;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nTrying to open an invalid file\n", 2), 1);
	buff = malloc(sizeof(char) * 100000);
	if (!buff)
		return (1);
	i = read(fd, buff, 100000);
	if (i == -1)
		return (ft_putstr_fd("Error\nTrying to read an invalid file\n", 2), 1);
	buff[i] = '\0';
	data->map = ft_split(buff, '\n');
	free(buff);
	if (check_square(data) || check_exit(data) || check_walls(data))
		return (ft_putstr_fd("Error\nInvalid map\n", 2), 1);
	data->win_width = ft_strlen(data->map[0]) * 32;
	data->win_height = get_height(data) * 32 + 32;
	data->nbr_coll = get_nb_coll(data);
	if (data->nbr_coll == 0)
		return (ft_putstr_fd("Error\nInvalid map\n", 2), 1);
	return (0);
}
