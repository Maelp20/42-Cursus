/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:58:51 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/07 18:40:01 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_window(t_data *data, int width, int height)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "So lonnnnng !");
	if (data->win_ptr == NULL)
		free(data->win_ptr);
}

int	get_height(t_data *data)
{
	int	i;
	
	i = 0;
	while (data->map[i])
		i++;
	return (i);
}

void	get_map_info(t_data *data, char *path)
{
	int		fd;
	char	*buff;
	int		i;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nTrying to open an invalid file\n", 2));
	buff = malloc(sizeof(char) * 100000);
	i = read(fd, buff, 100000);
	if (i == -1)
		return (ft_putstr_fd("Error\nTrying to read an invalid file\n", 2));
	buff[i] = '\0';
	data->map = ft_split(buff, '\n');
	printf("len = %d\n", ft_strlen(data->map[0]));
	data->win_width = ft_strlen(data->map[0]) * 32;
	data->win_height = get_height(data) * 32;
}

int	main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	get_map_info(&data, "./maps/map1.ber");
	put_window(&data, data.win_width, data.win_height);
	init_img(&data);
	put_elements(&data);
	hooks(&data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
