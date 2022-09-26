/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:55 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/15 17:31:13 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/inc/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		fd_file1;
	int		fd_file2;
	int		pipefd[2];

	pid_t	pid1;
	pid_t	pid2;

	char	**options;
	char	**envp;
	char	**paths;
	char	*cmd_path;
}			t_data;

int		ft_opens(t_data *data, char **av);
void	ft_close_n_wait(t_data *data);

#endif