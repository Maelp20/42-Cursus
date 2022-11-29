/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:24:37 by mpignet           #+#    #+#             */
/*   Updated: 2022/10/24 17:55:28 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static int	init_pipefd(t_data *d)
{
	int	i;

	i = 0;
	d->pipefd = malloc (sizeof(int *) * (d->nb_cmds));
	if (!d->pipefd)
		return (perror("Malloc"), 1);
	while (i < (d->nb_cmds - 1))
	{
		d->pipefd[i] = malloc (sizeof(int) * 2);
		if (!d->pipefd[i])
			return (perror("Malloc"), ft_free_array((void **)d->pipefd), 1);
		pipe(d->pipefd[i]);
		i++;
	}
	d->pipefd[i] = NULL;
	return (0);
}

static int	init_pids(t_data *d)
{
	d->pids = malloc (sizeof(int) * (d->nb_cmds));
	if (!d->pids)
		return (perror("Malloc"), 1);
	return (0);
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

static void	ft_open_files(t_data *d, int ac, char **av)
{
	if (d->heredoc)
	{
		d->fd_file1 = open(".heredoc.tmp", O_RDONLY);
		if (d->fd_file1 < 0)
			perror("infileLALA");
		d->fd_file2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (d->fd_file2 < 0)
			perror("outfile");
	}
	else
	{
		d->fd_file1 = open(av[1], O_RDONLY);
		if (d->fd_file1 < 0)
			perror("infile");
		d->fd_file2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (d->fd_file2 < 0)
			perror("outfile");
	}
}

int	init_data(t_data *d, int ac, char **av)
{
	if (is_heredoc(av))
		d->heredoc = 1;
	else
	{
		d->heredoc = 0;
		d->fd_file1 = 0;
		d->fd_file2 = 0;
	}
	if (ac < (5 + d->heredoc))
		return (ft_putstr_fd("Pipex: Not enough arguments\n", 2), 1);
	d->child = 0;
	d->nb_cmds = ac - (3 + d->heredoc);
	if (init_pids(d))
		return (1);
	if (init_pipefd(d))
		return (free(d->pids), 2);
	d->options = NULL;
	d->envp = NULL;
	d->paths = NULL;
	d->cmd_path = NULL;
	if (d->heredoc)
		ft_create_infile(d, av);
	ft_open_files(d, ac, av);
	return (0);
}
