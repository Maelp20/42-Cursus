/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:58:51 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/08 16:40:24 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_window(t_data *data, int width, int height)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "So lonnnnng !");
	if (data->win_ptr == NULL)
		free(data->win_ptr);
}

void	init_block(t_data *data)
{
	data->mlx_ptr = NULL ;
	data->win_ptr = NULL ;
	data->background = NULL ;
	data->wall = NULL ;
	data->coll = NULL ;
	data->exit = NULL ;
	data->player = NULL ;
	data->win_width = 0;
	data->win_height = 0;
	data->counter = 0;
	data->nbr_coll = 0;
	data->pos_x = 0;
	data->pos_y = 0;
}

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
		return (ft_putstr_fd("Error\nWrong number of arguments\n", 2), 1);
	init_block(&data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	parsing(&data, av[1]);
	put_window(&data, data.win_width, data.win_height);
	init_img(&data);
	put_elements(&data);
	hooks(&data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
