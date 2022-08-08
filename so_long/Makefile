# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 13:06:22 by mpignet           #+#    #+#              #
#    Updated: 2022/08/08 17:18:23 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS	= \
			main.c\
			put_elements.c\
			move.c\
			hooks.c\
			parsing.c\

OBJS	= ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = ./lib/libft
LIBFT = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ INCLUDING PRINTF ~~~~~~~ */
PRINTF_DIR = ./lib/ft_printf
PRINTF = ${PRINTF_DIR}/libftprintf.a

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = ./lib/minilibx-linux
MLX = ${MLX_DIR}/libmlx.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */

CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror
MFLAGS	= -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx ${MLX}
LFLAGS	= -L ${LIBFT_DIR} -lft
NAME	= so_long
RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			@make -C ${LIBFT_DIR} --no-print-directory
			@make -C ${PRINTF_DIR} --no-print-directory
			@make -C ${MLX_DIR} --no-print-directory
			@${CC} ${CFLAGS} ${OBJS} ${PRINTF} ${LFLAGS} ${MFLAGS} -o ${NAME}
			
clean:
			${RM} ${OBJS}
			@make clean -C lib/libft --no-print-directory
			@make clean -C lib/ft_printf --no-print-directory

fclean:		
			${RM} ${OBJS}
			${RM} ${NAME}
			@make fclean -C lib/libft --no-print-directory
			@make fclean -C lib/ft_printf --no-print-directory
			@make clean -C lib/minilibx-linux --no-print-directory

re:			fclean all

.PHONY: 	all clean fclean re