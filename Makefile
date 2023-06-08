# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 17:55:18 by laugarci          #+#    #+#              #
#    Updated: 2023/06/08 18:18:47 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server

CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
DEP_CLIENT = $(SRC_CLIENT:.c=.d)

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
DEP_SERVER = $(SRC_SERVER:.c=.d)

RM = rm -f

%.o: %.c $(LIBS) Makefile
	@$(CC) $(CFLAGS) -MMD -I./ -c $< -o $@

all:
	@$(MAKE) -C printf
	@$(MAKE) $(CLIENT)
	@$(MAKE) $(SERVER)

$(CLIENT):: $(OBJ_CLIENT)
	@$(MAKE) -C printf
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $@
	@echo "client compiled $<..."

$(CLIENT)::
	@echo -n

$(SERVER):: $(OBJ_SERVER)
	@$(MAKE) -C printf
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -o $@
	@echo "server compiled $<..."

$(SERVER)::
	@echo -n

clean:
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(DEP_SERVER) $(DEP_CLIENT)
	@$(MAKE) clean -C printf

fclean: clean
	@$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEP_CLIENT)
-include $(DEP_SERVER)
