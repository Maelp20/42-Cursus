/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:39 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/12 18:08:37 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static char	*ft_get_path_line(char **envp)
{
	char	*path_line;
	int		i;

	i = 0;
	while (envp[i])
	{
		path_line = ft_strnstr(envp[i], "PATH=", 5);
		if (path_line)
		{
			path_line = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			if (!path_line)
				return (NULL);
			break ;
		}
		i++;
	}
	return (path_line);
}

static char	*ft_get_path(char *cmd, char **envp)
{
	char	*path_line;
	char	*cmd_path;
	char	**paths;
	int		i;

	path_line = ft_get_path_line(envp);
	if (!path_line)
		return (NULL);
	paths = ft_split(path_line, ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

static int	ft_exec_cmd(int in, int out, t_data *data, char *cmd)
{
	if (dup2(in, STDIN_FILENO) == -1)
		return (1);
	if (dup2(out, STDOUT_FILENO) == -1)
		return (1);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	data->options = ft_split(cmd, ' ');
	if (!data->options)
		return (1);
	data->cmd_path = ft_get_path(data->options[0], data->envp);
	if (!data->cmd_path)
		return (1);
	execve(data->cmd_path, data->options, data->envp);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		return (ft_putstr_fd("Wrong number of arguments\n", 2), 1);
	if (ft_opens(&data, av))
		return (ft_putstr_fd("Failed opening a file\n", 2), 1);
	if (pipe(data.pipefd) == -1)
		return (ft_putstr_fd("Pipe failed\n", 2), 1);
	data.pid1 = fork();
	data.envp = envp;
	if (data.pid1 == -1)
		return (1);
	else if (data.pid1 == 0)
		ft_exec_cmd(data.fd_file1, data.pipefd[1], &data, av[2]);
	else if (data.pid1 > 0)
	{
		data.pid2 = fork();
		if (data.pid2 == -1)
			return (1);
		else if (data.pid2 == 0)
			ft_exec_cmd(data.pipefd[0], data.fd_file2, &data, av[3]);
		else if (data.pid2 > 0)
			ft_close_n_wait(&data);
	}
	return (0);
}
