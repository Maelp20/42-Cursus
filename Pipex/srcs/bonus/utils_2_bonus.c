/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:23:17 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/27 17:55:00 by mpignet          ###   ########.fr       */
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

char	*ft_get_path(t_data *data)
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

void	ft_free_int_array(int **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
