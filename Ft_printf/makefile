# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 19:07:50 by bgoron            #+#    #+#              #
#    Updated: 2023/11/11 16:32:15 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
ft_putnbr_base.c \
ft_putchar.c \
ft_putstr.c \
ft_strlen.c \
ft_sort.c \

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

all: $(NAME)

.PHONY: all clean fclean re