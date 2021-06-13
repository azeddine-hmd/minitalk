NAME = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SERVER_SRC = server.c \
			 utils.c \
			 mt_itoa.c \
			 mt_atoi.c \

CLIENT_SRC = client.c \
			 utils.c \
			 mt_itoa.c \
			 mt_atoi.c \

SERVER_OBJ = ${SERVER_SRC:.c=.o}
CLIENT_OBJ = ${CLIENT_OBJ:.c=.o}

all: $(NAME)

$(NAME): $(CLIENT)
	@$(CC) $(CFLAGS) $(SERVER_SRC) -o $(NAME)

$(CLIENT):
	@$(CC) $(CFLAGS) $(CLIENT_SRC) -o $(CLIENT)

clean:
	@rm -rf $(SERVER_OBJ) $(CLIENT_OBJ)

fclean:
	@rm -rf $(NAME) $(CLIENT)

re: fclean all

.PHONY: clean fclean re
