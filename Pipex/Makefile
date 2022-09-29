# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 15:45:58 by mpignet           #+#    #+#              #
#    Updated: 2022/09/29 17:25:15 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS	= \
			main.c\
			utils.c\

SRCS_B	= \
			main_bonus.c\
			utils_bonus.c\
			utils_2_bonus.c\
			init_bonus.c\

SRCDIR		= srcs/
SRCDIR_B	= srcs/bonus/
OBJDIR 		= objs
OBJS		= ${addprefix ${OBJDIR}/, ${SRCS:.c=.o}}
OBJS_B		= ${addprefix ${OBJDIR}/, ${SRCS_B:.c=.o}}
INC			= inc/pipex.h
INC_B		= inc/pipex_bonus.h

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a


# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */

CC		= gcc
CFLAGS	= -g -Wall -Wextra
LFLAGS	= -L ${LIBFT_DIR} -lft
NAME	= pipex
RM		= rm -fd

all:		${NAME}

${OBJDIR}/%.o : ${SRCDIR}%.c ${INC}
				mkdir -p ${OBJDIR}
				${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}/%.o : ${SRCDIR_B}%.c ${INC_B}
				mkdir -p ${OBJDIR}
				${CC} ${CFLAGS} -c $< -o $@

${LIBFT} :	
			make -C ${LIBFT_DIR} --no-print-directory

${NAME}:	${OBJS}	${LIBFT}
			${CC} ${CFLAGS} ${OBJS} ${LFLAGS} -o ${NAME}

bonus:		${OBJS_B} ${LIBFT}
			${CC} ${CFLAGS} ${OBJS_B} ${LFLAGS} -o ${NAME} 

clean:
			${RM} ${OBJS} ${OBJS_B} ${OBJDIR}
			make clean -C ${LIBFT_DIR} --no-print-directory

fclean:		
			${RM} ${OBJS} ${OBJS_B} ${OBJDIR}
			${RM} ${NAME}
			make fclean -C ${LIBFT_DIR} --no-print-directory

re:			fclean
			make all

.PHONY: 	all clean fclean re

.SILENT: