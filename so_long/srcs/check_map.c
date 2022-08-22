/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:39:04 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/22 17:07:47 by mpignet          ###   ########.fr       */
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
				return (1);
			j++;
		}
		if (data->map[i][j] != '1')
			return (1);
		i++;
	}
	if (check_walls_line (data, 0) || check_walls_line (data, i))
		return (1);
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
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (1);
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
			return (1);
		i++;
	}
	return (0);
}
