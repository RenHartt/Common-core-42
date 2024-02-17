# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:46:56 by bgoron            #+#    #+#              #
#    Updated: 2024/02/17 16:34:26 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

SRCS = srcs/parsing/exit.c \
	   srcs/parsing/check_prompt.c \
	   srcs/parsing/parse_prompt.c \
	   srcs/parsing/init_token.c \
	   srcs/prompt.c \

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@make -s -C Libft
	@$(CC) $(CLAGS) $(OBJS) -lreadline -o $(NAME) Libft/libft.a

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@make -s -C Libft fclean
	@rm -rf $(NAME)

re : fclean all

all: $(NAME)

.PHONY: all clean fclean re
