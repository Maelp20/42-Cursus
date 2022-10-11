/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:39 by mpignet           #+#    #+#             */
/*   Updated: 2022/10/11 18:58:13 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static void	redirect_fds(int in, int out, t_data *d)
{
	if (dup2(in, STDIN_FILENO) == -1)
	{
		ft_close_fds(d);
		exit_error("dup2", d);
	}
	if (dup2(out, STDOUT_FILENO) == -1)
	{
		ft_close_fds(d);
		exit_error("dup2", d);
	}
	ft_close_fds(d);
}

static void	ft_exec_cmd(int in, int out, t_data *d, char *cmd)
{
	redirect_fds(in, out, d);
	d->options = ft_split(cmd, ' ');
	if (!d->options)
		exit_error("malloc", d);
	if (ft_strchr(d->options[0], '/'))
	{
		if (access(d->options[0], F_OK | X_OK) != 0)
			exit_error("access", d);
		execve(d->options[0], d->options, d->envp);
		exit_error("execve", d);
	}
	d->cmd_path = ft_get_path(d);
	if (!d->cmd_path)
		exit_error(NULL, d);
	execve(d->cmd_path, d->options, d->envp);
	exit_error("execve", d);
}

static void	child(t_data *d, char **av)
{
	if (d->heredoc)
	{
		if (d->child == 0)
			ft_exec_cmd(d->fd_file1, d->pipefd[0][1], d, av[d->child + 3]);
		else if (d->child == d->nb_cmds - 1)
			ft_exec_cmd(d->pipefd[d->child - 1][0], d->fd_file2, d,
				av[d->child + 3]);
		else
			ft_exec_cmd(d->pipefd[d->child - 1][0],
				d->pipefd[d->child][1], d, av[d->child + 3]);
	}
	else
	{
		if (d->child == 0)
			ft_exec_cmd(d->fd_file1, d->pipefd[0][1], d, av[d->child + 2]);
		else if (d->child == d->nb_cmds - 1)
			ft_exec_cmd(d->pipefd[d->child - 1][0], d->fd_file2, d,
				av[d->child + 2]);
		else
			ft_exec_cmd(d->pipefd[d->child - 1][0],
				d->pipefd[d->child][1], d, av[d->child + 2]);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	d;

	if (init_data(&d, ac, av))
		return (1);
	d.envp = envp;
	while (d.child < d.nb_cmds)
	{
		d.pids[d.child] = fork();
		if (d.pids[d.child] == -1)
		{
			ft_close_fds(&d);
			exit_error("Fork", &d);
		}
		else if (d.pids[d.child] == 0)
			child(&d, av);
		d.child++;
	}
	ft_close_pipes(&d);
	ft_free_close(&d);
	ft_wait(&d);
	if (d.heredoc)
		unlink(".heredoc.tmp");
	return (0);
}
