# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:11:03 by mpignet           #+#    #+#              #
#    Updated: 2022/07/28 15:23:17 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=    \
								main.c\
								parsing.c\
								instructions.c\
								args_checks.c\
								sort_3.c\
								utils.c\
								get_index.c\
								presort.c\
								find_positions.c\
								sort_big.c\
								get_cost.c\
								do_moves.c\
							
OBJS = ${SRCS:.c=.o}

MAKE = make -C libft
LIBA = libft/libft.a
LIB = -L libft/ -lft	

NAME = push_swap

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

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