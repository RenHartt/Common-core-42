# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:46:56 by bgoron            #+#    #+#              #
#    Updated: 2024/02/16 22:10:09 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

SRCS = srcs/parsing/check_exit.c \
	   srcs/parsing/parse_prompt.c \
	   srcs/parsing/init_token.c \
	   srcs/parsing/main.c \

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@make -s -C Libft
	@$(CC) $(CLAGS) $(OBJS) -lreadline -o $(NAME) Libft/libft.a

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make clean -s -C Libft
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

all: $(NAME)

.PHONY: all clean fclean re
