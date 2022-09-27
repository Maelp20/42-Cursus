/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:55 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/27 17:55:35 by mpignet          ###   ########.fr       */
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
	int		*nb_cmds;
	int		**pipefd;

	pid_t	pid;

	char	**options;
	char	**envp;
	char	**paths;
	char	*cmd_path;
}			t_data;

void	ft_wait(t_data *data);
void	ft_free_array(void **tab);
void	ft_free_close(t_data *data);
void	init_data(t_data *data, int ac, char **av);
int		add_slash(t_data *data);
char	*ft_get_path(t_data *data);

#endif