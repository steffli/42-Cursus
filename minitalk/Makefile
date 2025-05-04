CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(PRINTF_DIR)
PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT = client
SERVER = server

all: $(PRINTF) $(CLIENT) $(SERVER)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT) -L$(PRINTF_DIR) -lftprintf

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER) -L$(PRINTF_DIR) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re