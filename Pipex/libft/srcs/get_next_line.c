/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:35:32 by mpignet           #+#    #+#             */
/*   Updated: 2022/10/11 16:16:08 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*clear_line_from_stash(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	j = -1;
	while (++j < i && stash[j])
		temp[j] = stash[j];
	temp[j] = '\0';
	j = 0;
	while (stash[i] && buffer[j])
		buffer[j++] = stash[i++];
	buffer[j] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*stash;
	static char		buffer[BUFFER_SIZE + 1];
	ssize_t			readed;
	char			*line_to_return;

	readed = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || fd > 1024)
		return (NULL);
	stash = NULL;
	stash = ft_strjoin1(stash, buffer);
	while (readed && !ft_new_line(stash))
	{
		if (!stash)
			return (NULL);
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free(stash), NULL);
		buffer[readed] = '\0';
		if (!readed && !stash[0])
			return (free(stash), NULL);
		stash = ft_strjoin1(stash, buffer);
	}
	line_to_return = clear_line_from_stash (stash, buffer);
	return (free (stash), line_to_return);
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