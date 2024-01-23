# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 13:38:45 by bgoron            #+#    #+#              #
#    Updated: 2024/01/23 16:50:13 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I Libft

SRCS = srcs/pipex.c \
	srcs/parsing.c \
	srcs/close.c \
	srcs/do_pipe.c \
	srcs/init.c \
	srcs/GNL.c \

OBJS = $(SRCS:.c=.o)
$(NAME) : $(OBJS)
	make -C Libft
	$(CC) $(CLAGS) $(OBJS) -o $(NAME) Libft/libft.a

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C Libft
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

all: $(NAME)

.PHONY: all clean fclean re
