# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 10:39:42 by bgoron            #+#    #+#              #
#    Updated: 2023/12/06 20:23:30 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
CFLAGS = -Wall -Werror -Wextra -g

SRCS = ft_fractol.c \
	   ft_utils.c \
	   ft_map.c \
	   ft_color.c \
	   ft_hook.c \
	   ft_set.c \
	   ft_screen.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make --quiet -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) -Lminilibx-linux -lmlx_Linux -I./minilibx-linux -lXext -lX11 -lm -lz -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

all: $(NAME)

.PHONY: all clean fclean re