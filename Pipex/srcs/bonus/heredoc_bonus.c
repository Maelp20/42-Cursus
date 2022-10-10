/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:49:46 by mpignet           #+#    #+#             */
/*   Updated: 2022/10/10 20:29:42 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

void	ft_create_infile(t_data *d, char **av)
{
	int		tmp_fd;
	int		stdin_fd;
	int		len;
	char	*line;

	tmp_fd = open(".heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp_fd < 0)
		exit_error("here.doc", d);
	stdin_fd = dup(STDIN_FILENO);
	ft_putstr_fd("here_doc > ", 1);
	line = get_next_line(stdin_fd);
	len = ft_strlen(av[2]);
	while(line)
	{
		if (!ft_strncmp(line, av[2], len) 
			&& ft_strlen(av[2]) + 1 == ft_strlen(line))
			break;
		ft_putstr_fd("here_doc > ", 1);
		ft_putstr_fd(line, tmp_fd);
		free(line);
		line = get_next_line(stdin_fd);
	}
	if (line)
		free(line);
	close (tmp_fd);
}

int	is_heredoc(t_data *d, char **av)
{
	if (!ft_strncmp(av[1], "here_doc", 9))
		return (ft_create_infile(d, av), 1);
	return (0);
}
