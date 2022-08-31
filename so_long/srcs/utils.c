/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:29:25 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/31 15:37:15 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	fill_line(t_data *data, char *line, int len, int x)
{
	int	i;

	i = 0;
	while (i < len)
	{
		data->map[x][i] = line[i];
		i++;
	}
	data->map[x][i] = '\0';
	return ;
}

void	find_player(t_data *data, int *x, int *y)
{
	while (data->map[*x])
	{
		*y = 0;
		while (data->map[*x][*y])
		{
			if (data->map[*x][*y] == 'P' || data->map[*x][*y] == 'L')
				return ;
			(*y)++;
		}
		(*x)++;
	}
}

int	init_map(t_data *data, char *path, int x)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nTrying to open an invalid file\n", 2), 1);
	line = get_next_line(fd);
	if (!line || check_empty_lines(line) == 1)
		return (free(line), 1);
	while (line)
	{
		len = 0;
		while (line[len] && line[len] != '\n')
			len++;
		data->map[x] = malloc(sizeof(char) * (len + 1));
		if (!data->map[x])
			return (close(fd), 1);
		fill_line(data, line, len, x);
		free(line);
		line = get_next_line(fd);
		x++;
	}
	data->map[x] = NULL;
	return (close(fd), 0);
}

int	get_map_length(char *path)
{
	char	*line;
	int		fd;
	int		len;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nTrying to open an invalid file\n", 2);
		return (-1);
	}
	line = get_next_line(fd);
	len = 0;
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}
