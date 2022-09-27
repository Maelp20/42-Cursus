/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:39 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/27 18:08:39 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static int	ft_exec_cmd(int in, int out, t_data *data, char *cmd)
{
	if (dup2(in, STDIN_FILENO) == -1)
		return (perror("dup2"), ft_free_close(data), 1);
	if (dup2(out, STDOUT_FILENO) == -1)
		return (perror("dup2"), ft_free_close(data), 1);
	if (data->pipefd[0] > -1)
		close(data->pipefd[0]);
	if (data->pipefd[1] > -1)
		close(data->pipefd[1]);
	data->options = ft_split(cmd, ' ');
	if (!data->options)
		return (perror("Malloc"), ft_free_close(data), 1);
	if (ft_strchr(data->options[0], '/'))
	{
		if (access(data->options[0], F_OK | X_OK) != 0)
			return (perror("Access"), ft_free_close(data), 1);
		execve(data->options[0], data->options, data->envp);
		return (perror("Execve"), ft_free_close(data), 1);
	}
	data->cmd_path = ft_get_path(data);
	if (!data->cmd_path)
		return (ft_free_close(data), 1);
	execve(data->cmd_path, data->options, data->envp);
	return (perror("Execve"), ft_free_close(data), 1);
}

int	child(t_data *data, char **av)
{
	if (data->child == 0)
		ft_exec_cmd(data->fd_file1, data->pipefd[1][1], &data, av[data->child + 2]);
	else if (data->child == data->nb_cmds)
		ft_exec_cmd(data->pipefd[2 * data->child - 2], data->fd_file2, &data, av[data->child + 2]);
	else
		ft_exec_cmd(data->pipefd[2 * data->child - 2], data->pipefd[2 * data->child + 1], &data, av[data.child + 2]);
	ft_free_close(&data);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	init_data(&data, ac, av);
	if (pipe(data.pipefd) == -1)
		return (perror("Pipe"), ft_free_close(&data), 1);
	data.envp = envp;
	data.nb_cmds = ac - 3;
	while (data.child < data.nb_cmds)
	{
		data.pid = fork();
		if (data.pid == -1)
			return (perror("Fork"), ft_free_close(&data), 1);
		else if (data.pid == 0)
			child(&data, av);
		else
			data.child++;
			return (ft_free_close(&data), ft_wait(&data), 0);
	}
}
