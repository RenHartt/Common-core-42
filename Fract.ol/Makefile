# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 10:39:42 by bgoron            #+#    #+#              #
#    Updated: 2023/12/04 16:02:12 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol.a
CC = clang
CFLAGS = -Wall -Wextra -Werror

SRCS = fractol.c \
	   mandelbrot.c \
	   julia.c \
	   utils.c \

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