# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:11:03 by mpignet           #+#    #+#              #
#    Updated: 2022/07/06 10:16:57 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=    \
								main.c\
								parsing.c\
								instructions.c\
								args_checks.c\
								sort_3.c\
								sort_big.c\
							
OBJS = ${SRCS:.c=.o}

# OBJS_B	= ${SRCS_B:.c=.o}

MAKE = make -C libft
LIBA = libft/libft.a
LIB = -L libft/ -lft

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME):	${OBJS} ${LIBA}
			${CC} ${CFLAGS} -o $@ ${OBJS} ${LIB}

# bonus:		${OBJS_B}
# 			ar rcs ${NAME} ${OBJS_B}

all: 		$(NAME)

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY: all clean fclean re