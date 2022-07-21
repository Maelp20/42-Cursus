# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:11:03 by mpignet           #+#    #+#              #
#    Updated: 2022/07/21 16:40:14 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=    \
								main.c\
								parsing.c\
								instructions.c\
								args_checks.c\
								sort_3.c\
								insertion_sort.c\
								utils.c\
							
OBJS = ${SRCS:.c=.o}

MAKE = make -C libft
LIBA = libft/libft.a
LIB = -L libft/ -lft

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME):	${OBJS} ${LIBA}
			${CC} ${CFLAGS} -o $@ ${OBJS} ${LIB}

all: 		$(NAME)

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY: all clean fclean re