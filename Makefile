# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 17:55:18 by laugarci          #+#    #+#              #
#    Updated: 2023/06/07 18:27:11 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
PRINTF_PATH = printf/
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -MMD

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
DEPS_CLIENT = $(SRC_CLIENT:.c=.d)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
DEPS_SERVER = $(SRC_SERVER:.c=.d)

all: subsystems
	$(OBJS_SERVER) $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(SRCS_SERVER) -o $(NAME_SERVER)
	$(CC) $(CFLAGS) $(SRCS_CLIENT) -o $(NAME_CLIENT)

subsystems:
	make -C $(PRINTF_PATH) all

client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(SRCS_CLIENT) -o $(NAME_CLIENT)

server: $(OBJS_SERVER) subsystems
	$(CC) $(CFLAGS) $(SRCS_SERVER) -o $(NAME_SERVER)

clean:
			$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
			$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all client server clean fclean re bonus
