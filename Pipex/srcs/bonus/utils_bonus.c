/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:19:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/14 18:15:50 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	init_data(t_data *data)
{
	data->fd_file1 = 0;
	data->fd_file2 = 0;
	data->pipefd[2] = 0;

	data->pid1 = 0;
	data->pid2 = 0;

	data->options = NULL;
	data->envp = NULL;
	data->cmd_path = NULL;
}

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
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	close(data->fd_file1);
	close(data->fd_file2);
}