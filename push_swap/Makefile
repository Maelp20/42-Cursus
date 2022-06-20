# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:11:03 by mpignet           #+#    #+#              #
#    Updated: 2022/06/20 17:15:36 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=    \
								main.c\
								parsing.c\
								instructions.c\
							
OBJS	= ${SRCS:.c=.o}

# OBJS_B	= ${SRCS_B:.c=.o}

NAME	= push_swap

CC	= gcc

# CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

# bonus:		${OBJS_B}
# 			ar rcs ${NAME} ${OBJS_B}

all: 		$(NAME)

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY: all clean fclean re ${NAME}