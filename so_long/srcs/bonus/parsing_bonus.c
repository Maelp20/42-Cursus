/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:38:46 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/25 19:46:43 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

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

static int	handle_read_err(int i)
{
	if (i == -1)
		return (ft_putstr_fd("Error\nTrying to read an invalid file\n", 2), 1);
	else if (i < 9)
		return (ft_putstr_fd("Error\nMap is too small\n", 2), 1);
	return (0);
}

static int	check_size(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (j > 79)
				return (ft_putstr_fd("Error\nMap is too large\n", 2), 1);
			j++;
		}
		i++;
	}
	if (i > 42)
		return (ft_putstr_fd("Error\nMap is too long\n", 2), 1);
	return (0);
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
	if (handle_read_err(i) == 1)
		return (free(buff), 1);
	buff[i] = '\0';
	data->map = ft_split(buff, '\n');
	free(buff);
	if (check_square(data) || check_exit(data) || check_walls(data)
		|| check_size(data))
		return (1);
	data->win_width = ft_strlen(data->map[0]) * 32;
	data->win_height = get_height(data) * 32;
	data->nbr_coll = get_nb_coll(data);
	if (data->nbr_coll == 0)
		return (ft_putstr_fd("Error\nWrong number of coll or players\n", 2), 1);
	return (0);
}
