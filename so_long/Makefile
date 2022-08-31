# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 13:06:22 by mpignet           #+#    #+#              #
#    Updated: 2022/08/31 15:38:35 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS	= \
			main.c\
			put_elements.c\
			move.c\
			hooks.c\
			parsing.c\
			check_map.c\
			utils.c\

SRCS_B	= \
			main_bonus.c\
			put_elements_bonus.c\
			move_bonus.c\
			hooks_bonus.c\
			parsing_bonus.c\
			check_map_bonus.c\
			display_score_bonus.c\
			utils_bonus.c\

SRCDIR		= srcs/
SRCDIR_B	= srcs/bonus/
OBJDIR 		= objs
OBJS		= ${addprefix ${OBJDIR}/, ${SRCS:.c=.o}}
OBJS_B		= ${addprefix ${OBJDIR}/, ${SRCS_B:.c=.o}}
INC			= inc/so_long.h
INC_B		= inc/so_long_bonus.h

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = ./lib/libft
LIBFT = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ INCLUDING PRINTF ~~~~~~~ */
PRINTF_DIR = ./lib/ft_printf
PRINTF = ${PRINTF_DIR}/libftprintf.a

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = ./lib/minilibx-linux
MLX	= ${MLX_DIR}/libmlx.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */

CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror
MFLAGS	= -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx ${MLX}
LFLAGS	= -L ${LIBFT_DIR} -lft
NAME	= so_long
RM		= rm -fd

all:		${NAME}

${OBJDIR}/%.o : ${SRCDIR}%.c ${INC}
				mkdir -p ${OBJDIR}
				${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}/%.o : ${SRCDIR_B}%.c ${INC_B}
				mkdir -p ${OBJDIR}
				${CC} ${CFLAGS} -c $< -o $@

${LIBFT} :
			@make -C ${LIBFT_DIR} --no-print-directory
			
${PRINTF} :
			@make -C ${PRINTF_DIR} --no-print-directory
			
${MLX} :	
			@make -C ${MLX_DIR} --no-print-directory

${NAME}:	${OBJS} ${LIBFT} ${PRINTF} ${MLX}
			@${CC} ${CFLAGS} ${OBJS} ${PRINTF} ${LFLAGS} ${MFLAGS} -o ${NAME}

bonus:		${OBJS_B} ${LIBFT} ${PRINTF} ${MLX}
			@${CC} ${CFLAGS} ${OBJS_B} ${PRINTF} ${LFLAGS} ${MFLAGS} -o ${NAME} 

clean:
			${RM} ${OBJS} ${OBJS_B} ${OBJDIR}
			@make clean -C lib/libft --no-print-directory
			@make clean -C lib/ft_printf --no-print-directory

fclean:		
			${RM} ${OBJS} ${OBJS_B} ${OBJDIR}
			${RM} ${NAME}
			@make fclean -C lib/libft --no-print-directory
			@make fclean -C lib/ft_printf --no-print-directory
			@make clean -C lib/minilibx-linux --no-print-directory

re:			fclean all

.PHONY: 	all clean fclean re