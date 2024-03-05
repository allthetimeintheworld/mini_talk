# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 11:03:34 by jadyar            #+#    #+#              #
#    Updated: 2024/03/05 14:45:15 by jadyar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Files
SERVER_SRC		=	src/server.c \
					src/utils.c
					
CLIENT_SRC		=	src/client.c \
					src/utils.c

# Sources and objects

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS)

# ------------------------------ Constant strings ------------------------------

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

SERVER_NAME	=	server

CLIENT_NAME1	=	client1
CLIENT_NAME2	=	client2

NAME		=	server

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

SERV_READY	=	echo "\n Server is ready!\n"

CLI_READY	=	echo "\n Client is ready!\n"

CLEANED		=	echo "\n $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Rules ------------------------------

bonus: all

all: $(NAME)

$(NAME): comp_start ft_server ft_client

comp_start:
	@$(COMP_START)

ft_server: $(SERVER_OBJS)
	@$(GCC) $(FLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)
	@$(SERV_READY)

ft_client: $(CLIENT_OBJS)
	@$(CC) $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME1)
	@$(CC) $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME2)
	@$(CLI_READY)

clean:
	@rm -rf $(OBJS)
	@$(CLEANED)

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME1) $(CLIENT_NAME2)
	@$(FCLEANED)

.c.o:
	@${CC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY: all minitalk server client clean fclean re
