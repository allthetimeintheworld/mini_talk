# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 11:03:34 by jadyar            #+#    #+#              #
#    Updated: 2024/03/05 11:05:35 by jadyar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft -lft

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

.PHONY: all clean fclean re

all: client server

client: $(CLIENT_OBJS) libft/libft.a
    $(CC) $(CFLAGS) $(CLIENT_OBJS) $(LDFLAGS) -o $@

server: $(SERVER_OBJS) libft/libft.a
    $(CC) $(CFLAGS) $(SERVER_OBJS) $(LDFLAGS) -o $@

libft/libft.a:
    $(MAKE) -C libft

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    $(MAKE) -C libft clean
    rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
    $(MAKE) -C libft fclean
    rm -f client server

re: fclean all
