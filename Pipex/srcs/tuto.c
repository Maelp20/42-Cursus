/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:35:08 by mpignet           #+#    #+#             */
/*   Updated: 2022/09/07 16:36:07 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// main for pipex : get the cmd valid path / execute cmd with execve function
/* int	main(int ac, char **av, char **envp)
{
	char	*cmd_path;
	char	*options[3] = {"ls", "-la", NULL};
	char	*cmd;
	
	(void)ac;
	(void)av;
	cmd = "ls";
	cmd_path = get_cmd_path(cmd, envp);
	if (!cmd_path)
	{
		printf("Error getting path\n");
		return (1);
	}
	execve(cmd_path, options, envp);
	printf("OK\n");
	free(cmd_path);
	return (0);
}
 */

// 2 childs, use of waitpid in the parent process
/* int main(void)
{
    pid_t   pid1;
    pid_t   pid2;
    pid_t   res;
    int     status;

    pid1 = fork();
    if (pid1 == -1)
        return (1);
    if (pid1 == 0)
    {
        usleep(50000);
        printf("Child 1 : I'm the first child !\n");
        return (0);
    }
    else if (pid1 > 0)
    {
        pid2 = fork();
        if (pid2 == -1)
            return (1);
        else if(pid2 == 0)
        {
            usleep(49900);
            printf("Child 2 : I'm the second child...\n");
            return (2);
        }
        else if(pid2 > 0)
        {
            printf("Parent : I have two children !\n");
            res = waitpid(pid1, &status, 0);
            printf("Parent : I received my first child %d\n", res);
            if (WIFEXITED(status))
                printf("Parent : It exited successfully, exit code %d\n", WEXITSTATUS(status));
            else
                printf("Parent : It was interrupted...\n");
            res = waitpid(pid2, &status, 0);
            printf("Parent : I received my second child %d\n", res);
            if (WIFEXITED(status))
                printf("Parent : It exited successfully, exit code %d\n", WEXITSTATUS(status));
            else
                printf("Parent : It was interrupted...\n");
        }
    }
    return (0);
}
 */

// pass some info in a file from child to parent
/* int main(void)
{
	pid_t	id;
	int		pipefd[2];
	char	secret[30];
	int		reader;
	char	buffer[30];

	if(pipe(pipefd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (1);
	else if (id == 0)
	{
		// Child Process
		printf("Child : I'm the child\n");
		close(pipefd[0]); // Nothing to read here
		printf("Child : I'm writing my secret in the pipe\n");
		ft_strlcpy(secret, "I am your child", 16);
		write(pipefd[1], secret, ft_strlen(secret));
		close(pipefd[1]);
		return (0);
	}
	else
	{
		// Parent Process
		printf("Parent : I have one child\n");
		close(pipefd[1]); // Nothing to write here
		waitpid(id, NULL, 0);
		printf("Parent : I received my child. What is its secret ?\n");
		reader = read(pipefd[0], buffer, 30);
		if (reader == -1)
			return (1);
		buffer[reader] = '\0';
		printf("Parent: Oh boy! The secret is : \"%s\"\n", buffer);
	}
} */

int	main(void)
{
	int		fd;
	int		fd_copy;
	int		reader;
	char	buff[15];

	ft_putstr_fd("caca\n", 1);
	ft_printf("My PID is %d\n", getpid());
	fd = open("test.txt", O_RDONLY);
	if (!fd)
		return (1);
	fd_copy = dup(fd);
	if (!fd_copy)
		return (1);
	reader = read(fd, buff, 10);
	if (reader == -1)
		return (1);
	buff[reader] = '\0';
	ft_printf("fd %d contains : %s\n", fd, buff);
	reader = read(fd_copy, buff, 10);
	if (reader == -1)
		return (1);
	buff[reader] = '\0';
	ft_printf("fd %d contains : %s\n", fd_copy, buff);
	while (1)
		;
	return (0);
}