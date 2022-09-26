/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:19:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/26 17:15:01 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	init_data(t_data *data, int ac, char **av)
{
	if (ac != 5)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		exit (1);
	}
	data->fd_file1 = 0;
	data->fd_file2 = 0;
	data->pipefd[0] = 0;
	data->pipefd[1] = 0;
	data->pid1 = 0;
	data->pid2 = 0;
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

	waitpid(data->pid1, &status, 0);
	waitpid(data->pid2, &status, 0);
}

void	ft_free_array(char **tab)
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
	if (data->options)
		ft_free_array(data->options);
	if (data->cmd_path)
		free(data->cmd_path);
	if (data->pipefd[0] > -1)
		close(data->pipefd[0]);
	if (data->pipefd[1] > -1)
		close(data->pipefd[1]);
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
