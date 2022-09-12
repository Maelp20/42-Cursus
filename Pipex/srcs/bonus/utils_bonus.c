/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:19:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/12 18:00:36 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

int	ft_opens(t_data *data, char **av)
{
	data->fd_file1 = open(av[1], O_RDONLY);
	if (data->fd_file1 <= 0)
		return (1);
	data->fd_file2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_file2 <= 0)
		return (close(data->fd_file1), 1);
	return (0);
}

void	ft_close_n_wait(t_data *data)
{
	int	status;

	close(data->pipefd[0]);
	close(data->pipefd[1]);
	close(data->fd_file1);
	close(data->fd_file2);
	waitpid(data->pid1, &status, 0);
	waitpid(data->pid2, &status, 0);
}
