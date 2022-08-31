/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:58:51 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/31 16:06:46 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

static void	destroy_nbr(t_data *data)
{
	if (data->nbr.zero != NULL)
		mlx_destroy_image(data->mlx, data->nbr.zero);
	if (data->nbr.one != NULL)
		mlx_destroy_image(data->mlx, data->nbr.one);
	if (data->nbr.two != NULL)
		mlx_destroy_image(data->mlx, data->nbr.two);
	if (data->nbr.three != NULL)
		mlx_destroy_image(data->mlx, data->nbr.three);
	if (data->nbr.four != NULL)
		mlx_destroy_image(data->mlx, data->nbr.four);
	if (data->nbr.five != NULL)
		mlx_destroy_image(data->mlx, data->nbr.five);
	if (data->nbr.six != NULL)
		mlx_destroy_image(data->mlx, data->nbr.six);
	if (data->nbr.seven != NULL)
		mlx_destroy_image(data->mlx, data->nbr.seven);
	if (data->nbr.eight != NULL)
		mlx_destroy_image(data->mlx, data->nbr.eight);
	if (data->nbr.nine != NULL)
		mlx_destroy_image(data->mlx, data->nbr.nine);
}

static void	clear_array(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	return ;
}

static void	destroy_all(t_data *data)
{
	if (data->background != NULL)
		mlx_destroy_image(data->mlx, data->background);
	if (data->wall != NULL)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->coll != NULL)
		mlx_destroy_image(data->mlx, data->coll);
	if (data->exit != NULL)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->player != NULL)
		mlx_destroy_image(data->mlx, data->player);
	if (data->play_left != NULL)
		mlx_destroy_image(data->mlx, data->play_left);
	if (data->enemy != NULL)
		mlx_destroy_image(data->mlx, data->enemy);
	if (data->map != NULL)
		clear_array(data);
	if (data->win != NULL)
		close_window(data);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

static void	init_block(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->background = NULL;
	data->wall = NULL;
	data->coll = NULL;
	data->exit = NULL;
	data->player = NULL;
	data->play_left = NULL;
	data->enemy = NULL;
	data->map = NULL;
	data->win_width = 0;
	data->win_height = 0;
	data->counter = 0;
	data->nbr_coll = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_putstr_fd("Error\nWrong number of arguments\n", 2), 1);
	if (ft_strcmp((av[1] + ft_strlen(av[1]) - 4), ".ber"))
		return (ft_putstr_fd("Error\nInvalid name file\n", 2), 1);
	init_block(&data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (ft_putstr_fd("Error\nMlx init failed\n", 2), 1);
	if (parsing(&data, av[1]))
		return (destroy_all(&data), 1);
	put_window(&data, data.win_width, data.win_height);
	if (init_img(&data) || init_nbr(&data))
		return (destroy_nbr(&data), destroy_all(&data), 1);
	put_elements(&data);
	hooks(&data);
	mlx_loop(data.mlx);
	destroy_nbr(&data);
	destroy_all(&data);
	return (0);
}
