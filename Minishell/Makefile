# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:46:56 by bgoron            #+#    #+#              #
#    Updated: 2024/02/14 15:27:44 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

SRCS = srcs/main.c \
	   srcs/parse.c \

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@make -C Libft
	@$(CC) $(CLAGS) $(OBJS) -lreadline -o $(NAME) Libft/libft.a

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make fclean -C Libft
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

all: $(NAME)

.PHONY: all clean fclean re
