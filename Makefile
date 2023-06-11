# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 17:55:18 by laugarci          #+#    #+#              #
#    Updated: 2023/06/11 09:49:16 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server
PRINTF_PATH = printf/
PRINTF_LIB = $(PRINTF_PATH)printf.a
CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
DEP_CLIENT = $(SRC_CLIENT:.c=.d)

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
DEP_SERVER = $(SRC_SERVER:.c=.d)

RM = rm -f

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -MMD -I./ -c $< -o $@

all: subsystems
	@$(MAKE) $(CLIENT)
	@$(MAKE) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	@$(CC)  $(CFLAGS) $(OBJ_CLIENT) -o $@
	@echo "client compiled $<..."

subsystems:
	@make -C $(PRINTF_PATH) all

$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(PRINTF_LIB) $(OBJ_SERVER) -o $@
	@echo "server compiled $<..."

clean:
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(DEP_SERVER) $(DEP_CLIENT)
	@$(MAKE) clean -C printf

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(PRINTF_LIB)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEP_CLIENT)
-include $(DEP_SERVER)
