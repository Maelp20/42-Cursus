/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:24:37 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/28 16:54:50 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static int	init_pipefd(t_data *d, int ac)
{
	int	i;

	i = 0;
	d->pipefd = malloc (sizeof(int *) * (ac - 1));
	if (!d->pipefd)
		return (perror("Malloc"), 1);
	while(i < (ac - 2))
	{
		d->pipefd[i] = malloc (sizeof(int) * 2);
		if (!d->pipefd[i])
			return (perror("Malloc"), ft_free_array((void **)d->pipefd), 1);
		d->pipefd[i][0] = 0;
		d->pipefd[i][1] = 0;
		i++;
	}
	d->pipefd[i] = NULL;
	return (0);
}

static int	init_pids(t_data *d, int ac)
{
	d->pids = malloc (sizeof(int) * (ac - 3));
	if (!d->pids)
		return(perror("Malloc"), 1);
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

int	init_data(t_data *d, int ac, char **av)
{
	d->fd_file1 = 0;
	d->fd_file2 = 0;
	d->child = 0;
	d->nb_cmds = 0;
	if(init_pids(d, ac))
		return (1);
	if (init_pipefd(d, ac))
		return (free(d->pids), 2);
	d->options = NULL;
	d->envp = NULL;
	d->paths = NULL;
	d->cmd_path = NULL;
	d->fd_file1 = open(av[1], O_RDONLY);
	if (d->fd_file1 < 0)
		perror("file1");
	d->fd_file2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->fd_file2 < 0)
		perror("file2");
	return (0);
}