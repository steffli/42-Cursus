CC = cc 
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS=	ft_printf_utils.c ft_printf.c ft_printf_ptr.c

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:	
		rm -f $(OBJS)
fclean:
		rm -f $(NAME)
re:		clean $(NAME)

.PHONY:	all clean fclean re
