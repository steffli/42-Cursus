# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stliu <stliu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 16:23:47 by stliu             #+#    #+#              #
#    Updated: 2025/03/19 12:14:03 by stliu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME=libft.a

SRCS=				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
					ft_toupper.c ft_tolower.c  ft_strchr.c ft_strrchr.c  ft_strnstr.c \
					ft_strncmp.c ft_atoi.c ft_calloc.c   ft_strdup.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c  ft_split.c  ft_itoa.c  ft_strmapi.c \
					ft_striteri.c ft_putchar_fd.c  ft_putstr_fd.c ft_putendl_fd.c \
					ft_putnbr_fd.c ft_strlen.c ft_memchr.c ft_memcmp.c ft_strlcat.c

BONUS=				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
					ft_lstmap.c

OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS) $(OBJS_BONUS)
		
fclean:	clean 
		rm -f $(NAME)
		
re:		fclean $(NAME)

bonus:		$(OBJS) $(OBJS_BONUS)
				ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

.PHONY:		all clean fclean re bonus