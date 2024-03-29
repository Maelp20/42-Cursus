/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:28:36 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/31 15:32:32 by mpignet          ###   ########.fr       */
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
# define PATH_PLAYER "./assets/Dino.xpm"
# define PATH_PLAY_LEFT "./assets/DinoLeft.xpm"

# include <stdio.h>

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*background;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*player;
	void	*play_left;

	char	**map;

	int		win_width;
	int		win_height;
	int		counter;
	int		nbr_coll;
}			t_data;

char	*get_next_line(int fd);
int		parsing(t_data *data, char *path);
int		init_map(t_data *data, char *path, int x);
void	hooks(t_data *data);
int		init_img(t_data *data);
void	put_elements(t_data *data);
int		close_window(t_data *data);
int		get_map_length(char *path);

int		check_square(t_data *data);
int		check_exit(t_data *data);
int		check_walls(t_data *data);
int		check_empty_lines(char *line);

void	find_player(t_data *data, int *x, int *y);
void	move(t_data *data, int keysym);

#endif