/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:19:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/27 17:56:57 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static int	init_pipefd(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	data->pipefd = malloc (sizeof(int *) * (ac - 1));
	if (!data->pipefd)
		return (ft_free_int_array(data->pipefd, 0), 1);
	while(i < (ac - 2))
	{
		data->pipefd[i] = malloc (sizeof(int) * 2);
		if (!data->pipefd[i])
			return (ft_free_int_array(data->pipefd, i), 1);
		data->pipefd[i][0] = 0;
		data->pipefd[i][1] = 0;
		i++;
	}
	data->pipefd[i] = NULL;
	return (0);
}

void	init_data(t_data *data, int ac, char **av)
{
	if (ac < 5)
	{
		ft_putstr_fd("Not enough arguments\n", 2);
		exit (1);
	}
	data->fd_file1 = 0;
	data->fd_file2 = 0;
	data->child = 0;
	data->nb_cmds = 0;
	init_pipefd(data->pipefd, ac , av);
	data->pid = 0;
	data->options = NULL;
	data->envp = NULL;
	data->paths = NULL;
	data->cmd_path = NULL;
	data->fd_file1 = open(av[1], O_RDONLY);
	if (data->fd_file1 < 0)
		perror("file1");
	data->fd_file2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_file2 < 0)
		perror("file2");
}

void	ft_wait(t_data *data)
{
	int	status;

	waitpid(data->pid, &status, 0);
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

void	ft_free_close(t_data *data)
{
	int	i;

	i = 0;
	if (data->options)
		ft_free_array(data->options);
	if (data->cmd_path)
		free(data->cmd_path);
	while (i < data->nb_cmds)
	{	
		if (data->pipefd[i] > -1)
			close(data->pipefd[i]);
		i++;
	}
	if (data->fd_file1 > -1)
		close(data->fd_file1);
	if (data->fd_file2 > -1)
		close(data->fd_file2);
}

int	add_slash(t_data *data)
{
	char	*tmp;
	int		i;

	i = -1;
	while (data->paths[++i])
	{
		tmp = data->paths[i];
		data->paths[i] = ft_strjoin(data->paths[i], "/");
		if (!data->paths[i])
			return (perror("Malloc"), free(tmp), 1);
		free(tmp);
	}
	return (0);
}
