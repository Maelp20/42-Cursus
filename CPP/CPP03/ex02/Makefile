# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:06:41 by mpignet           #+#    #+#              #
#    Updated: 2023/03/11 19:41:36 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ################################## #
#               COMMAND              #
# ################################## #

CC			= c++
MKDIR		= mkdir -p
RM			= rm -rf

# ################################## #
#              EXEC NAME             #
# ################################## #

NAME		= FragTrap

# ################################## #
#               SOURCES              #
# ################################## #

C_DIR		= src
C_FILES		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

SRCS		= $(patsubst %, $(C_DIR)/%, $(C_FILES))

# ################################## #
#               OBJECTS              #
# ################################## #

O_DIR		= objs
O_FILES		= $(C_FILES:.cpp=.o)
OBJS		= $(patsubst %, $(O_DIR)/%, $(O_FILES))

# ################################## #
#                FLAGS               #
# ################################## #

CFLAGS		= -Wall -Wextra -Werror -g -std=c++98

# ################################## #
#                INCLUDES            #
# ################################## #

CINCLUDES	=	-I ./inc

# ################################## #
#                RULES               #
# ################################## #

all:	$(NAME)

$(O_DIR):
			$(MKDIR) $(O_DIR)

$(O_DIR)/%.o: $(C_DIR)/%.cpp
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@


$(NAME): $(O_DIR) $(OBJS)
			$(CC) $(OBJS) $(CFLAGS) -o $@

# ################################## #
#                CLEAN               #
# ################################## #

clean:
			$(RM) $(O_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re

.NOTPARALLEL:fclean