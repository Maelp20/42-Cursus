/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:55 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/12 16:03:40 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct	s_data
{
	int	fd_file1;
	int	fd_file2;
	int	pipefd[2];

	pid_t	pid1;
	pid_t	pid2;

	char	**options;
	char	*cmd_path;
}			t_data;

#endif