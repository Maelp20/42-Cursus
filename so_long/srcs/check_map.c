/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:39:04 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/25 20:35:33 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_walls_line(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->map[i][j])
	{
		if (data->map[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i + 1])
	{
		j = 0;
		while (data->map[i][j + 1])
		{
			if (data->map[i][0] != '1')
				return (ft_putstr_fd("Error\nMissing wall in map\n", 2), 1);
			j++;
		}
		if (data->map[i][j] != '1')
			return (ft_putstr_fd("Error\nMissing wall in map\n", 2), 1);
		i++;
	}
	if (check_walls_line (data, 0) || check_walls_line (data, i))
		return (ft_putstr_fd("Error\nMissing wall in map\n", 2), 1);
	return (0);
}

int	check_exit(t_data *data)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				exit++;
			else if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'C' && data->map[i][j] != 'P')
				return (ft_putstr_fd("Error\nInvalid char in map\n", 2), 1);
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (ft_putstr_fd("Error\nWrong number of exits\n", 2), 1);
	return (0);
}

int	check_square(t_data *data)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (len != ft_strlen(data->map[i]))
			return (ft_putstr_fd("Error\nMap is not a rectangle\n", 2), 1);
		i++;
	}
	return (0);
}

int	check_empty_lines(char *buff, int len)
{
	int	i;

	i = 1;
	buff[len] = '\0';
	while (buff[i])
	{
		if (buff[i] == '\n' && buff[i - 1] == '\n')
			return (ft_putstr_fd("Error\nEmpty line in file\n", 2), 1);
		i++;
	}
	return (0);
}
