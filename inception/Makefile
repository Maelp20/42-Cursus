# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 17:11:06 by mpignet           #+#    #+#              #
#    Updated: 2023/06/16 17:13:03 by mpignet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YML_PATH = ./srcs/docker-compose.yml

all:
	@docker-compose -f $(YML_PATH) up -d

down: 
	@docker-compose -f $(YML_PATH) down

re:
	@docker-compose -f $(YML_PATH) up --build --force-recreate -d

clean:
	@docker stop $$(docker ps -qa);\
    docker rm $$(docker ps -qa);\
    docker rmi -f $$(docker images -qa);\
    docker volume rm $$(docker volume ls -q);\
	rm -rf /home/mpignet/data/mariadb/*;\
	rm -rf /home/mpignet/data/wordpress/*;\
    docker network rm srcs_docker_network;\

.PHONY: all down re clean