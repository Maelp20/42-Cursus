/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:49:46 by mpignet           #+#    #+#             */
/*   Updated: 2022/10/11 16:47:05 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	ft_create_infile(t_data *d, char **av)
{
	int		tmp_fd;
	int		stdin_fd;
	char	*line;

	tmp_fd = open(".heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp_fd < 0)
		exit_error("heredoc", d);
	stdin_fd = dup(STDIN_FILENO);
	ft_putstr_fd("pipex heredoc > ", 1);
	line = get_next_line(stdin_fd);
	while (line)
	{
		if (!ft_strncmp(line, av[2], ft_strlen(av[2]))
			&& ft_strlen(av[2]) + 1 == ft_strlen(line))
			break ;
		ft_putstr_fd("pipex heredoc > ", 1);
		ft_putstr_fd(line, tmp_fd);
		free(line);
		line = get_next_line(stdin_fd);
	}
	if (line)
		free(line);
	close (stdin_fd);
	close (tmp_fd);
}

int	is_heredoc(char **av)
{
	if (!ft_strncmp(av[1], "here_doc", 9))
		return (1);
	return (0);
}
