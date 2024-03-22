# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:46:56 by bgoron            #+#    #+#              #
#    Updated: 2024/03/22 14:08:13 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -g3 -Wall -Wextra -Werror -pthread -fsanitize=thread -static-libsan

IFLAGS = -I ./include

SRCS = src/philo.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c $^ -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

all: $(NAME)

.PHONY: all clean fclean re