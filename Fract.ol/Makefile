# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 10:39:42 by bgoron            #+#    #+#              #
#    Updated: 2023/12/13 14:14:46 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
CFLAGS = -Wall -Werror -Wextra -I MacroLibX/includes -O3

SRCS = ft_fractol.c \
	   ft_utils.c \
	   ft_map.c \
	   ft_color.c \
	   ft_hook.c \
	   ft_set.c \
	   ft_screen.c \
	   ft_input.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ ./MacroLibX/libmlx.so -lSDL2 -lm

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

all: $(NAME)

.PHONY: all clean fclean re
