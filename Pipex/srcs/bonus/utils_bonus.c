/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:19:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/28 17:01:11 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	ft_wait(t_data *d)
{
	int	status;
	int	i;

	i = -1;
	while (++i < d->nb_cmds)
		waitpid(d->pids[i], &status, 0);
}

void	ft_free_array(void **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	ft_close_pipes(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb_cmds)
	{	
		if (d->pipefd[i][0] > -1)
			close(d->pipefd[i][0]);
		if (d->pipefd[i][1] > -1)
			close(d->pipefd[i][1]);
		i++;
	}	
}

void	ft_free_close(t_data *d)
{
	if (d->options)
		ft_free_array((void **)d->options);
	if (d->cmd_path)
		free(d->cmd_path);
	if (d->pids)
		free(d->pids);
	if (d->fd_file1 > -1)
		close(d->fd_file1);
	if (d->fd_file2 > -1)
		close(d->fd_file2);
}

void	ft_close_fds(t_data *d)
{
	if (d->fd_file1 != -1)
		close (d->fd_file1);
	if (d->fd_file2 != -1)
		close (d->fd_file2);
	ft_close_pipes(d);
}