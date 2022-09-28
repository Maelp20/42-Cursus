/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:19:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/28 12:28:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static int	init_pipefd(t_data *d, int ac)
{
	int	i;

	i = 0;
	d->pipefd = malloc (sizeof(int *) * (ac - 1));
	if (!d->pipefd)
		return (ft_free_array((void **)d->pipefd), 1);
	while(i < (ac - 2))
	{
		d->pipefd[i] = malloc (sizeof(int) * 2);
		if (!d->pipefd[i])
			return (ft_free_array((void **)d->pipefd), 1);
		d->pipefd[i][0] = 0;
		d->pipefd[i][1] = 0;
		i++;
	}
	d->pipefd[i] = NULL;
	return (0);
}

void	init_data(t_data *d, int ac, char **av)
{
	if (ac < 5)
	{
		ft_putstr_fd("Not enough arguments\n", 2);
		exit (1);
	}
	d->fd_file1 = 0;
	d->fd_file2 = 0;
	d->child = 0;
	d->nb_cmds = 0;
	init_pipefd(d, ac);
	d->pid = 0;
	d->options = NULL;
	d->envp = NULL;
	d->paths = NULL;
	d->cmd_path = NULL;
	d->fd_file1 = open(av[1], O_RDONLY);
	if (d->fd_file1 < 0)
		perror("file1");
	d->fd_file2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->fd_file2 < 0)
		perror("file2");
}

void	ft_wait(t_data *d)
{
	int	status;

	waitpid(d->pid, &status, 0);
}

void	ft_free_array(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_pipes(t_data *d)
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
	if (d->fd_file1 > -1)
		close(d->fd_file1);
	if (d->fd_file2 > -1)
		close(d->fd_file2);
}

int	add_slash(t_data *d)
{
	char	*tmp;
	int		i;

	i = -1;
	while (d->paths[++i])
	{
		tmp = d->paths[i];
		d->paths[i] = ft_strjoin(d->paths[i], "/");
		if (!d->paths[i])
			return (perror("Malloc"), free(tmp), 1);
		free(tmp);
	}
	return (0);
}
