/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:35:32 by mpignet           #+#    #+#             */
/*   Updated: 2022/05/20 16:25:15 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *save)
{
	char	*str;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)ft_calloc(sizeof(char), (i + 2));
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
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_save(char *save)
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
	str = (char *)ft_calloc(sizeof(char), (ft_strlen(save) - i + 1));
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

	buff = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret && !(ft_strchr(save, '\n')))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		if (ret)
		{
			buff[ret] = '\0';
			save = ft_strjoin(save, buff);
		}
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		*line;

	if ((fd < 0 || fd >= 4096) || BUFFER_SIZE < 1)
		return (NULL);
	save[fd] = ft_readnfill(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_get_line(save[fd]);
	save[fd] = ft_new_save(save[fd]);
	return (line);
}

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int    main(void)
// {
//     int    fd1;
//     int    fd2;
//     int    fd3;
//     char    *result1 = NULL;
//     char    *result2 = NULL;
//     char    *result3 = NULL;
//     int    i;

//     i = 0;
//     fd1 = open("41", O_RDONLY);
//     fd2 = open("42", O_RDONLY);
//     fd3 = open("43", O_RDONLY);
//     if (fd1 == -1 || fd2 == -1 || fd3 == -1)
//         return (0);
//     while (i < 5)
//     {
//         result1 = get_next_line(fd1);
//         printf("%sLEN%ld\n", result1, ft_strlen(result1));
//         free (result1);
//         result2 = get_next_line(fd2);
//         printf("%sLEN%ld\n", result2, ft_strlen(result2));
//         free (result2);
//         result3 = get_next_line(fd3);
//         printf("%sLEN%ld\n", result3, ft_strlen(result3));
//         free (result3);
//         i++;
//     }
//     close(fd1);
//     close(fd2);
//     close(fd3);
//     return (0);
// }