/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:28:36 by mpignet           #+#    #+#             */
/*   Updated: 2022/08/23 15:39:51 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define PATH_ENEMY "./assets/Eggplant.xpm"

# define PATH_ZERO "./assets/nbr/zero.xpm"
# define PATH_ONE "./assets/nbr/one.xpm"
# define PATH_TWO "./assets/nbr/two.xpm"
# define PATH_THREE "./assets/nbr/three.xpm"
# define PATH_FOUR "./assets/nbr/four.xpm"
# define PATH_FIVE "./assets/nbr/five.xpm"
# define PATH_SIX "./assets/nbr/six.xpm"
# define PATH_SEVEN "./assets/nbr/seven.xpm"
# define PATH_EIGHT "./assets/nbr/eight.xpm"
# define PATH_NINE "./assets/nbr/nine.xpm"

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct s_nbr {
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
}		t_nbr;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*background;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*player;
	void	*play_left;
	void	*enemy;
	t_nbr	nbr;

	char	**map;

	int		win_width;
	int		win_height;
	int		counter;
	int		nbr_coll;

}		t_data;

char	*get_next_line(int fd);
int		parsing(t_data *data, char *path);
void	hooks(t_data *data);
void	init_img(t_data *data);
void	init_nbr(t_data *data);
void	put_elements(t_data *data);
void	put_window(t_data *data, int width, int height);
void	put_background(t_data *data, int j);
int		close_window(t_data *data);

int		check_square(t_data *data);
int		check_exit(t_data *data);
int		check_walls(t_data *data);

void	find_player(t_data *data, int *x, int *y);
void	move(t_data *data, int keysym);
void	move_up(t_data *data, int x, int y);
void	move_down(t_data *data, int x, int y);
void	move_left(t_data *data, int x, int y);
void	move_right(t_data *data, int x, int y);
void	display_score(t_data *data);

#endif