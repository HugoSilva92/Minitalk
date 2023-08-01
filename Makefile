# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 18:33:41 by huolivei          #+#    #+#              #
#    Updated: 2023/01/14 14:19:14 by huolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
SRCS = mandatory/server.c
SRCS_BONUS = bonus/server_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
SRCC = mandatory/client.c
SRCC_BONUS = bonus/client_bonus.c
OBJS_SRCC = $(SRCC:.c=.o)
OBJS_SRCC_BONUS = $(SRCC_BONUS:.c=.o)
INC = mandatory/minitalk.h
INC_BONUS = bonus/minitalk_bonus.h
LIBFT = libft/libft.a
LIBFT_DIR = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SERVER): $(OBJS) $(INC)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(SERVER)

$(CLIENT): $(OBJS_SRCC) $(INC)
	$(CC) $(CFLAGS) $(OBJS_SRCC) $(LIBFT) -o $(CLIENT)

bonus : $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SERVER_BONUS): $(OBJS_BONUS) $(INC_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJS_SRCC_BONUS) $(INC_BONUS)
	$(CC) $(CFLAGS) $(OBJS_SRCC_BONUS) $(LIBFT) -o $(CLIENT_BONUS)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(OBJS_SRCC) $(OBJS_BONUS) $(OBJS_SRCC_BONUS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(SERVER).o $(SERVER) $(CLIENT).o $(CLIENT) $(SERVER_BONUS).o $(SERVER_BONUS) $(CLIENT_BONUS).o $(CLIENT_BONUS)

re: fclean all

.PHONY: all, bonus, clean, fclean, re
