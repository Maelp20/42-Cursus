/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:39 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/15 17:14:02 by mpignet          ###   ########.fr       */
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

static char	*ft_check_access(char *cmd, char **paths)
{
	char	*cmd_path;
	int		i;

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

static char	*ft_get_path(t_data *data)
{
	char	*path_line;
	char	*cmd_path;

	path_line = ft_get_path_line(data->envp);
	if (!path_line)
		return (NULL);
	data->paths = ft_split(path_line, ':');
	if (!data->paths)
		return (free(path_line), NULL);
	add_slash(data);
	cmd_path = ft_check_access(data->options[0], data->paths);
	if (cmd_path)
		return (cmd_path);
	return (free(path_line), ft_free_array(data->paths), NULL);
}

static int	ft_exec_cmd(int in, int out, t_data *data, char *cmd)
{
	if (dup2(in, STDIN_FILENO) == -1)
		return (ft_free_close(data), 1);
	if (dup2(out, STDOUT_FILENO) == -1)
		return (ft_free_close(data), 1);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	data->options = ft_split(cmd, ' ');
	if (!data->options)
		return (ft_free_close(data), 1);
	if (check_absolute_path(data->options[0]))
	{
		if (execve(data->options[0], data->options, data->envp))
			return (ft_free_close(data), 1);
		ft_free_close(data);
		return (0);
	}
	data->cmd_path = ft_get_path(data);
	if (!data->cmd_path)
		return (ft_free_close(data), 1);
	if (execve(data->cmd_path, data->options, data->envp))
		return (ft_free_close(data), 1);
	ft_free_close(data);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 5)
		return (ft_putstr_fd("Wrong number of arguments\n", 2), 1);
	init_data(&data);
	if (ft_opens(&data, av) || pipe(data.pipefd) == -1)
		return (ft_putstr_fd("Failed opening a file, or Pipe failed\n", 2), 1);
	data.envp = envp;
	data.pid1 = fork();
	if (data.pid1 == -1)
		return (1);
	else if (data.pid1 == 0)
	{
		if (ft_exec_cmd(data.fd_file1, data.pipefd[1], &data, av[2]))
			return (ft_putstr_fd("1st command failed\n", 2), 1);
	}
	data.pid2 = fork();
	if (data.pid2 == -1)
		return (1);
	else if (data.pid2 == 0)
	{
		if (ft_exec_cmd(data.pipefd[0], data.fd_file2, &data, av[3]))
			return (ft_putstr_fd("2nd command failed\n", 2), 1);
	}
	return (ft_free_close(&data), ft_wait(&data), 0);
}
