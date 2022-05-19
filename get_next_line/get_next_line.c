/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:04:54 by mpignet           #+#    #+#             */
/*   Updated: 2022/05/19 16:29:00 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char *ft_get_line(char *save)
{
	char	*str;
	int		i;

	i = 0;
	if (!save[i])
		return(NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *) malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_new_save(char *save)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *) malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}

char	*ft_readnfill(int fd, char *save)
{
	char	*buff;
	int		ret;

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret && !(ft_strchr(save, '\n')))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return(NULL);
		}
		if (ret)
		{
			buff[ret] = '\0';
			save = ft_strjoin(save, buff);
		}
	}
	free(buff);
	return(save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_readnfill(fd, save);
	if (!save)
		return(NULL);
	line = ft_get_line(save);
	//printf ("line: |%s|\n", line);
	save = ft_new_save(save);
	//printf ("save final : |%s|\n", save);
	return (line);
}

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int	fd;

// 	fd = open("42", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		return (1);
// 	}
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }