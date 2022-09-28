/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:23:17 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/28 12:29:37 by mpignet          ###   ########.fr       */
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
	return (ft_putstr_fd("Access: command not found", 2), NULL);
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
