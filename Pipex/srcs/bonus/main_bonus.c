/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:39 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/29 16:13:48 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static void	ft_exec_cmd(int in, int out, t_data *d, char *cmd)
{
	if (dup2(in, STDIN_FILENO) == -1)
		exit_error("dup2");
	if (dup2(out, STDOUT_FILENO) == -1)
		exit_error("dup2");
	ft_close_fds(d);
	d->options = ft_split(cmd, ' ');
	if (!d->options)
		exit_error("malloc");
	if (ft_strchr(d->options[0], '/'))
	{
		if (access(d->options[0], F_OK | X_OK) != 0)
			exit_error("access");
		execve(d->options[0], d->options, d->envp);
		exit_error("execve");
	}
	d->cmd_path = ft_get_path(d);
	if (!d->cmd_path)
		exit_error(NULL);
	execve(d->cmd_path, d->options, d->envp);
	exit_error("execve");
}

void	child(t_data *d, char **av)
{
	if (d->child == 0)
	{
		// ft_putstr_fd("exec type 1\n", 2);
		ft_exec_cmd(d->fd_file1, d->pipefd[0][1], d, av[d->child + 2]);
	}
	else if (d->child == d->nb_cmds - 1)
	{
		// ft_putstr_fd("exec type 2\n", 2);
		ft_exec_cmd(d->pipefd[d->child - 1][0], d->fd_file2, d,
					 av[d->child + 2]);
	}
	else
	{
		// ft_putstr_fd("exec type 3\n", 2);
		ft_exec_cmd(d->pipefd[d->child - 1][0],
					d->pipefd[d->child][1], d, av[d->child + 2]);		
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	d;
	if (ac < 5)
		return (ft_putstr_fd("Not enough arguments\n", 2), 1);
	if (init_data(&d, ac, av))
		return (1);
	d.envp = envp;
	while (d.child < d.nb_cmds)
	{
		d.pids[d.child] = fork();
		if (d.pids[d.child] == -1)
			return (perror("Fork"), ft_free_close(&d), 2);
		else if (d.pids[d.child] == 0)
			child(&d, av);	
		d.child++;
	}
	ft_close_pipes(&d);
	ft_free_close(&d);
	ft_wait(&d);
	return (0);
}
