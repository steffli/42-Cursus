CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME=libft.a

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f *.o $(OBJS)
fclean:
	clean rm -f $(NAME)
re:		fclean $(NAME)

.PHONY:		all clean fclean re