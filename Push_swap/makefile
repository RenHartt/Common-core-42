# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 10:39:42 by bgoron            #+#    #+#              #
#    Updated: 2024/01/09 14:57:47 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang
CFLAGS = -Wall -Werror -Wextra -g

SRCS = pushswap.c \
	   ft_check_utils.c \
	   ft_index.c \
	   ft_init.c \
	   ft_lst_utils.c \
	   ft_parse.c \
	   ft_push_and_swap.c \
	   ft_reverse_and_rotate.c \
	   ft_sort_big.c \
	   ft_sort_small.c \
	   ft_split.c \
	   ft_str_utils.c\

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
