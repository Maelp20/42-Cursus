/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:57:17 by mpignet           #+#    #+#             */
/*   Updated: 2022/10/11 16:43:18 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	redirect_fds(int in, int out, t_data *data)
{
	if (dup2(in, STDIN_FILENO) == -1)
	{
		perror("dup2");
		ft_free_close(data);
		exit (1);
	}
	if (dup2(out, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		ft_free_close(data);
		exit (1);
	}
	ft_close_fds(data);
}

void	ft_free_array(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_wait(t_data *data)
{
	int	status;

	waitpid(data->pid1, &status, 0);
	waitpid(data->pid2, &status, 0);
}

void	ft_close_fds(t_data *data)
{
	if (data->fd_file1 > -1)
		close (data->fd_file1);
	if (data->fd_file2 > -1)
		close (data->fd_file2);
	if (data->pipefd[0] > -1)
		close(data->pipefd[0]);
	if (data->pipefd[1] > -1)
		close(data->pipefd[1]);
}

void	ft_free_close(t_data *data)
{
	if (data->options)
		ft_free_array(data->options);
	if (data->cmd_path)
		free(data->cmd_path);
	ft_close_fds(data);
}
