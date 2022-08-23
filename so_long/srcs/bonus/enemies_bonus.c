/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:00:01 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/23 14:50:44 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

// void	go_up(t_data *data, int i, int j)
// {
// 	if (data->map[i - 1][j] == '0' || data->map[i - 1][j] == 'P')
// 	{
// 		data->map[i][j] = '0';
// 		data->map[i - 1][j] = 'M';
// 	}
// }

// void	go_down(t_data *data, int i, int j)
// {
// 	if (data->map[i + 1][j] == '0' || data->map[i + 1][j] == 'P')
// 	{
// 		data->map[i][j] = '0';
// 		data->map[i + 1][j] = 'M';
// 	}
// }

// void	go_left(t_data *data, int i, int j)
// {
// 	if (data->map[i][j - 1] == '0' || data->map[i][j - 1] == 'P')
// 	{
// 		data->map[i][j] = '0';
// 		data->map[i][j - 1] = 'M';
// 	}	
// }

// void	go_right(t_data *data, int i, int j)
// {
// 	if (data->map[i][j + 1] == '0' || data->map[i][j + 1] == 'P')
// 	{
// 		data->map[i][j] = '0';
// 		data->map[i][j + 1] = 'M';
// 	}
// }

// void	patroil(t_data *data, int i, int j)
// {
// 	int	value;

// 	srand(time(NULL));
// 	value = (rand() % 4) + 1;
// 	if (value == 1)
// 		go_up(data, i, j);
// 	else if (value == 2)
// 		go_down(data, i, j);
// 	else if (value == 3)
// 		go_left(data, i, j);
// 	else if (value == 4)
// 		go_right(data, i, j);
// }

// void	move_enemies(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (data->map[i])
// 	{
// 		j = 0;
// 		while (data->map[i][j])
// 		{
// 			if (data->map[i][j] == 'M')
// 			{
// 				patroil(data, i, j);
// 				break;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }