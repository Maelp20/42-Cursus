/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:39 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/12 16:11:14 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_get_path(char *cmd, char **envp)
{
	char	*path_line;
	char	*cmd_path;
	char	**paths;
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
			break;
		}
		i++;
	}
	paths = ft_split(path_line, ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
	i = 0;
	while(paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
}

int	ft_exec_cmd(int in, int out, t_data *data, char *cmd)
{
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	data->options = ft_split(cmd, ' ');
	if (!data->options)
		return (1);
}

int main(int ac, char **av, char **envp)
{
	t_data	data;
	
	if (ac != 5)
		return (ft_putstr_fd("Wrong number of arguments\n", 2), 1);
	pipe(data.pipefd);
	data.pid1 = fork();
	if (data.pid1 == -1)
		return (1);
	else if (data.pid1 == 0)
	{
		data.fd_file1 = open(av[1], O_RDONLY);
		ft_exec_cmd(data.fd_file1, data.pipefd[1], &data, av[2]);
	}
	else if (data.pid1 > 0)
	{
		data.pid2 = fork();
		if (data.pid2 == -1)
			return (1);
		else if (data.pid2 == 0)
		{
			// Child 2
		}
		else if (data.pid2 > 0)
		{
			// Parent
		}
	}
	return (0);
}