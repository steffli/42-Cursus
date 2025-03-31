CC = cc 
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a

SRCS=	get_next_line.c get_next_line_utils.c 
OBJS=$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: 
		rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re
