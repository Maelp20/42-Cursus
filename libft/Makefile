# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 16:11:03 by mpignet           #+#    #+#              #
#    Updated: 2022/09/07 14:38:19 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS	=    \
                                ft_isalpha.c\
								ft_memchr.c\
								ft_putchar_fd.c\
								ft_strchr.c\
								ft_strlcpy.c\
								ft_strrchr.c\
								ft_atoi.c\
								ft_isascii.c\
								ft_memcmp.c\
								ft_putendl_fd.c\
								ft_strdup.c\
								ft_strlen.c\
								ft_strtrim.c\
								ft_bzero.c\
								ft_isdigit.c\
								ft_memcpy.c\
								ft_putnbr_fd.c\
								ft_striteri.c\
								ft_strmapi.c\
								ft_substr.c\
								ft_calloc.c\
								ft_isprint.c\
								ft_memmove.c\
								ft_putstr_fd.c\
								ft_strjoin.c\
								ft_strncmp.c\
								ft_tolower.c \
								ft_isalnum.c \
								ft_itoa.c \
								ft_memset.c\
								ft_split.c\
								ft_strlcat.c\
								ft_strnstr.c\
								ft_toupper.c\
                                ft_lstnew.c\
								ft_lstiter.c\
								ft_lstlast.c\
								ft_lstadd_back.c\
								ft_lstadd_front.c\
								ft_lstsize.c\
								ft_lstdelone.c\
								ft_lstclear.c\
								ft_lstmap.c\
								get_next_line.c\
								get_next_line_utils.c\
								ft_printf.c\
								ft_printhexa.c\
								ft_printnbr_unsigned.c\
								ft_printnbr.c\
								ft_printptr.c\
								ft_utility_printf.c\

SRCDIR		= srcs/
OBJDIR 		= objs
OBJS		= ${addprefix ${OBJDIR}/, ${SRCS:.c=.o}}
INC			= inc/libft.h

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror
NAME	= libft.a
RM		= rm -fd

all:		${NAME}

${OBJDIR}/%.o : ${SRCDIR}%.c ${INC}
				mkdir -p ${OBJDIR}
				${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} ${OBJDIR}

fclean:		
			${RM} ${OBJS} ${OBJDIR}
			${RM} ${NAME}

re:			fclean
			make all

.PHONY: 	all clean fclean re