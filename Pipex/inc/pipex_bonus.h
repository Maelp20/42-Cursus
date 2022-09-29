/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:55 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/29 17:14:46 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/inc/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_data
{
	int		fd_file1;
	int		fd_file2;
	int		child;
	int		nb_cmds;
	int		**pipefd;

	pid_t	*pids;

	char	**options;
	char	**envp;
	char	**paths;
	char	*cmd_path;
}			t_data;

void	ft_wait(t_data *d);
void	ft_free_array(void **tab);
void	ft_free_close(t_data *d);
int		init_data(t_data *d, int ac, char **av);
int		add_slash(t_data *d);
char	*ft_get_path(t_data *d);
void	ft_close_pipes(t_data *d);
void	ft_close_fds(t_data *d);
void	exit_error(char *err, t_data *d);

#endif