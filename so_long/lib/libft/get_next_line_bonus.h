/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:57:35 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/06 13:54:41 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

char	*ft_spec_strchr(char *s, int c);
char	*ft_spec_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_readnfill(int fd, char *save);
char	*ft_new_save(char *save);
char	*ft_get_line(char *save);

#endif