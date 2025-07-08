# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shintarokohtake <shintarokohtake@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/06 16:21:28 by shintarokoh       #+#    #+#              #
#    Updated: 2025/07/08 20:15:23 by shintarokoh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := server client
SERVER_OBJS := server.o
CLIENT_OBJS := client.o
SERVER_SRCS := server.c
CLIENT_SRCS := client.c
OBJS := server.o client.o
SRCS := server.c client.c
RM := rm -f


all : $(NAME)

server : $(SERVER_OBJS)
	$(CC) $(CFLAGS) $< -o $@

client : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME) 

re : fclean all

.PHONY : all clean fclean re
