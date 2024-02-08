 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 13:38:45 by bgoron            #+#    #+#              #
#    Updated: 2024/01/28 21:20:22 by bgoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

SRCS = srcs/pipex.c \
	srcs/close.c \
	srcs/do_pipe.c \
	srcs/init.c \
	srcs/exit.c \

SRCS_BONUS = srcs_bonus/pipex_bonus.c \
	srcs_bonus/close_bonus.c \
	srcs_bonus/do_pipe_bonus.c \
	srcs_bonus/init_bonus.c \
	srcs_bonus/exit_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJS)
	@make -C Libft
	@$(CC) $(CLAGS) $(OBJS) -o $(NAME) Libft/libft.a

bonus : $(OBJS_BONUS)
	@make -C Libft
	@$(CC) $(CLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) Libft/libft.a

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make fclean -C Libft
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)

re : fclean all

all: $(NAME)

.PHONY: all clean fclean re
