# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 13:06:22 by mpignet           #+#    #+#              #
#    Updated: 2022/08/02 16:51:48 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= \
			gnl/get_next_line_bonus.c\
			gnl/get_next_line_utils_bonus.c\
			main.c\
			so_long.c\

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

CC		= gcc

CFLAGS	= -g -Wall -Wextra

RM		= rm -f

MINILIB = "./minilibx-linux/"

LIBFLAGS = -lmlx -lXext -lX11 -lXrender -lm

$(NAME):	${OBJS}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${MINILIB} ${LIBFLAGS}
			
all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re