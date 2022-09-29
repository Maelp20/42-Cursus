/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:23:17 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/29 17:50:10 by mpignet          ###   ########.fr       */
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
				return (perror("malloc"), NULL);
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
			return (perror("malloc"), NULL);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (perror("access"), NULL);
}

char	*ft_get_path(t_data *d)
{
	char	*path_line;
	char	*cmd_path;

	path_line = ft_get_path_line(d->envp);
	if (!path_line)
		return (NULL);
	d->paths = ft_split(path_line, ':');
	if (!d->paths)
		return (free(path_line), NULL);
	if (add_slash(d))
		return (free(path_line), ft_free_array((void **)d->paths), NULL);
	cmd_path = ft_check_access(d->options[0], d->paths);
	if (!cmd_path)
		return (free(path_line), ft_free_array((void **)d->paths), NULL);
	return (free(path_line), ft_free_array((void **)d->paths), cmd_path);
}

void	exit_error(char *err, t_data *d)
{
	if (!err)
	{
		ft_free_close(d);
		free(d->pids);
		exit(5);
	}
	ft_free_close(d);
	free(d->pids);
	perror(err);
	if (!err)
		exit(5);
	if (ft_strncmp(err, "dup2", 5))
		exit(1);
	else if (ft_strncmp(err, "malloc", 7))
		exit(2);
	else if (ft_strncmp(err, "access", 7))
		exit(3);
	else if (ft_strncmp(err, "execve", 7))
		exit(4);		
}