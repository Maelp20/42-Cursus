/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:42:39 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/28 17:03:34 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex_bonus.h"

static int	ft_exec_cmd(int in, int out, t_data *d, char *cmd)
{
	ft_printf("Child in exec cmd : %d\n", d->child);
	if (dup2(in, STDIN_FILENO) == -1)
		return (perror("1st dup2"), ft_close_pipes(d), ft_free_close(d), 1);
	if (dup2(out, STDOUT_FILENO) == -1)
		return (perror("2nd dup2"), ft_close_pipes(d), ft_free_close(d), 1);
	ft_close_fds(d);
	d->options = ft_split(cmd, ' ');
	if (!d->options)
		return (perror("Malloc"), ft_close_pipes(d), ft_free_close(d), 1);
	if (ft_strchr(d->options[0], '/'))
	{
		if (access(d->options[0], F_OK | X_OK) != 0)
			return (perror("Access"), ft_close_pipes(d), ft_free_close(d), 1);
		execve(d->options[0], d->options, d->envp);
		return (perror("Execve"), ft_close_pipes(d), ft_free_close(d), 1);
	}
	d->cmd_path = ft_get_path(d);
	if (!d->cmd_path)
		return (ft_free_close(d), 1);
	execve(d->cmd_path, d->options, d->envp);
	return (perror("Execve"), ft_close_pipes(d), ft_free_close(d), 1);
}

void	child(t_data *d, char **av)
{
	// int	i;

	// i = -1;
	if (d->child == 0)
	{
		// close(d->pipefd[0][0]);
		ft_exec_cmd(d->fd_file1, d->pipefd[0][1], d, av[d->child + 2]);
	}
	else if (d->child == d->nb_cmds)
	{
		// while (++i < d->child)
		// {
		// 	close(d->pipefd[i][0]);
		// 	close(d->pipefd[i][1]);
		// }
		close(d->pipefd[d->child][1]);
		ft_exec_cmd(d->pipefd[d->child - 1][0], d->fd_file2, d,
					 av[d->child + 2]);	
	}
	else
	{
		// while (++i < (d->child - 1))
		// {
		// 	ft_putstr_fd("boucle\n", 2);
		// 	close(d->pipefd[i][0]);
		// 	close(d->pipefd[i][1]);
		// }
		ft_putstr_fd("On va exec\n", 2);
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
	d.nb_cmds = ac - 3;
	while (d.child < d.nb_cmds - 1)
	{
		ft_printf("Child in main : %d\n", d.child);
		d.pids[d.child] = fork();
		if (d.pids[d.child] == -1)
			return (perror("Fork"), ft_free_close(&d), 2);
		else if (d.pids[d.child] == 0)
			child(&d, av);
		d.child++;
	}
	ft_close_pipes(&d);
	return (ft_free_close(&d), ft_wait(&d), 0);
}
