NAME = minitalk
CC = gcc
CFLAGS = -Wall -Werror -Wextra \

SERVER_SRC = server.c \
			 utils.c \
			 mt_itoa.c \
			 mt_atoi.c \
			 buffer.c \

CLIENT_SRC = client.c \
			 utils.c \
			 mt_itoa.c \
			 mt_atoi.c \
			 buffer.c \

SERVER_BONUS_SRC = server.c \
				   utils.c \
				   mt_itoa.c \
				   mt_atoi.c \
				   buffer_bonus.c \

CLIENT_BONUS_SRC = client.c \
				   utils.c \
				   mt_itoa.c \
				   mt_atoi.c \
				   buffer_bonus.c \

SERVER_OBJ = ${SERVER_SRC:.c=.o}
CLIENT_OBJ = ${CLIENT_SRC:.c=.o}
SERVER_BONUS_OBJ = ${SERVER_BONUS_SRC:.c=.o}
CLIENT_BONUS_OBJ = ${CLIENT_BONUS_SRC:.c=.o}

all: $(NAME)

$(NAME): server client

server:
	@$(CC) $(CFLAGS) $(SERVER_SRC) -o server

client:
	@$(CC) $(CFLAGS) $(CLIENT_SRC) -o client

bonus:
	@$(CC) $(CFLAGS) $(SERVER_BONUS_SRC) -o server
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_SRC) -o client

clean:
	@rm -rf $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)

fclean:
	@rm -rf $(NAME) server client

re: fclean all

.PHONY: clean fclean re bonus
