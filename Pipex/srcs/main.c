/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:39 by mpignet           #+#    #+#             */
/*   Updated: 2022/10/11 16:42:12 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
				return (perror("Malloc"), NULL);
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
		if (!cmd_path)
			return (perror("Malloc"), NULL);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (ft_putstr_fd("Access: command not found\n", 2), NULL);
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
	if (add_slash(data))
		return (free(path_line), ft_free_array(data->paths), NULL);
	cmd_path = ft_check_access(data->options[0], data->paths);
	if (!cmd_path)
		return (free(path_line), ft_free_array(data->paths), NULL);
	return (free(path_line), ft_free_array(data->paths), cmd_path);
}

static int	ft_exec_cmd(int in, int out, t_data *data, char *cmd)
{
	redirect_fds(in, out, data);
	data->options = ft_split(cmd, ' ');
	if (!data->options)
		return (perror("Malloc"), ft_free_close(data), 1);
	if (ft_strchr(data->options[0], '/'))
	{
		if (access(data->options[0], F_OK | X_OK) != 0)
		{
			perror("Access");
			ft_free_close(data);
			exit (1);
		}
		execve(data->options[0], data->options, data->envp);
		return (perror("Execve"), ft_free_close(data), 1);
	}
	data->cmd_path = ft_get_path(data);
	if (!data->cmd_path)
	{
		ft_free_close(data);
		exit(1);
	}
	execve(data->cmd_path, data->options, data->envp);
	return (perror("Execve"), ft_free_close(data), 1);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	init_data(&data, ac, av);
	if (pipe(data.pipefd) == -1)
		return (perror("Pipe"), ft_free_close(&data), 1);
	data.envp = envp;
	data.pid1 = fork();
	if (data.pid1 == -1)
		return (perror("Fork"), ft_free_close(&data), 1);
	else if (data.pid1 == 0)
		ft_exec_cmd(data.fd_file1, data.pipefd[1], &data, av[2]);
	else
	{
		data.pid2 = fork();
		if (data.pid2 == -1)
			return (perror("Fork"), 1);
		else if (data.pid2 == 0)
			ft_exec_cmd(data.pipefd[0], data.fd_file2, &data, av[3]);
		return (ft_free_close(&data), ft_wait(&data), 0);
	}
}
