# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:11:03 by mpignet           #+#    #+#              #
#    Updated: 2022/06/24 12:21:23 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=    \
								main.c\
								parsing.c\
								instructions.c\
							
OBJS = ${SRCS:.c=.o}

# OBJS_B	= ${SRCS_B:.c=.o}

LIB = -L libft/ -lft
LIBA = libft/libft.a

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME):	${OBJS} ${LIB}
			${CC} ${CFLAGS} -o $@ ${OBJS} ${LIBA}

# bonus:		${OBJS_B}
# 			ar rcs ${NAME} ${OBJS_B}

all: 		$(NAME)

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY: all clean fclean re ${NAME}