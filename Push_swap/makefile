# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 10:39:42 by bgoron            #+#    #+#              #
#    Updated: 2023/12/17 19:52:05 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap
CC = clang
CFLAGS = -Wall -Werror -Wextra

SRCS = pushswap.c \
	   ft_init.c \
	   ft_push.c \
	   ft_swap.c \
	   ft_rotate.c \
	   ft_reverse.c \
	   ft_sort.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

all: $(NAME)

.PHONY: all clean fclean re
