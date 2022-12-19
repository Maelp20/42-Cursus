# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 15:45:58 by mpignet           #+#    #+#              #
#    Updated: 2022/12/19 12:49:26 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS	= \
			main.c\
			init.c\
			eat_routine.c\
			supervisor.c\
			utils.c\

SRCDIR		= srcs/
OBJDIR 		= objs
OBJS		= ${addprefix ${OBJDIR}/, ${SRCS:.c=.o}}
INC			= inc/philo.h
CINC		= -I ./inc/

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */

CC		= gcc
CFLAGS	= -g3 -Wall -Wextra -Werror -fsanitize=thread
NAME	= philo
RM		= rm -fd

all:		${NAME}

${OBJDIR}/%.o : ${SRCDIR}%.c ${INC}
				mkdir -p ${OBJDIR}
				${CC} ${CFLAGS} ${CINC} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS} ${OBJDIR}

fclean:		
			${RM} ${OBJS} ${OBJDIR}
			${RM} ${NAME}

re:			fclean
			make all

.PHONY: 	all clean fclean re

.SILENT: