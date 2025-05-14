# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stliu <stliu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 16:46:50 by stliu             #+#    #+#              #
#    Updated: 2025/05/14 00:15:22 by stliu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(PRINTF_DIR) -I$(LIBFT_DIR)

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PUSH_SWAP_SRCS = push_swap_utils.c rotate_utils.c rotate_util_left.c stack_utils.c syntax_check.c main.c

PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

PUSH_SWAP = push_swap

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(PRINTF) $(LIBFT) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJS) -o $(PUSH_SWAP) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PUSH_SWAP_OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(PUSH_SWAP_OBJS)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re