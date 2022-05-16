# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 18:01:15 by mpignet           #+#    #+#              #
#    Updated: 2022/05/16 18:56:14 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=    \
						ft_printf.c\
						ft_printhexa.c\
						ft_printnbr_unsigned.c\
						ft_utility_printf.c\
						ft_printnbr.c\
						ft_printptr.c 
							
OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

all: 		$(NAME)

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

.PHONY: all clean fclean re ${NAME}