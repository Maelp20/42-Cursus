# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:11:03 by mpignet           #+#    #+#              #
#    Updated: 2022/05/12 12:25:44 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=    \
                                ft_isalpha.c\
								ft_memchr.c\
								ft_putchar_fd.c\
								ft_strchr.c\
								ft_strlcpy.c\
								ft_strrchr.c\
								ft_atoi.c\
								ft_isascii.c\
								ft_memcmp.c\
								ft_putendl_fd.c\
								ft_strdup.c\
								ft_strlen.c\
								ft_strtrim.c\
								ft_bzero.c\
								ft_isdigit.c\
								ft_memcpy.c\
								ft_putnbr_fd.c\
								ft_striteri.c\
								ft_strmapi.c\
								ft_substr.c\
								ft_calloc.c\
								ft_isprint.c\
								ft_memmove.c\
								ft_putstr_fd.c\
								ft_strjoin.c\
								ft_strncmp.c\
								ft_tolower.c \
								ft_isalnum.c \
								ft_itoa.c \
								ft_memset.c\
								ft_split.c\
								ft_strlcat.c\
								ft_strnstr.c\
								ft_toupper.c \

SRCS_B	=    \
                                ft_lstnew.c\
								ft_lstiter.c\
								ft_lstlast.c\
								ft_lstadd_back.c\
								ft_lstnew.c\
								ft_lstadd_front.c\
								ft_lstsize.c\
								ft_lstdelone.c\
								ft_lstclear.c\
								ft_lstmap.c\
							
OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

NAME	= libft.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

bonus:		${OBJS_B}
			ar rcs ${NAME} ${OBJS_B}

all: 		$(NAME)

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY: all clean fclean re ${NAME}