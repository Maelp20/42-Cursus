/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:28:36 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/08 16:42:36 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>

# define PATH_BG "./assets/Brick.xpm"
# define PATH_COLL "./assets/Burger.xpm"
# define PATH_WALL "./assets/Apple.xpm"
# define PATH_EXIT "./assets/Hospital.xpm"
# define PATH_PLAYER "./assets/HotDog.xpm"

# include <stdio.h>

typedef struct s_data {
	
	void	*mlx_ptr;
	void	*win_ptr;
	void	*background;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*player;

	char	**map;

	int		win_width;
	int		win_height;
	int		counter;
	int		nbr_coll;
	int		pos_x;
	int		pos_y;
}			t_data;

char	*get_next_line(int fd);
void	parsing(t_data *data, char *path);
void	hooks(t_data *data);
void	init_img(t_data *data);
void	put_elements(t_data *data);

void	move_up(t_data *data, int x, int y);
void	move_down(t_data *data, int x, int y);
void	move_left(t_data *data, int x, int y);
void	move_right(t_data *data, int x, int y);

# endif