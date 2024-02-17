/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:27:33 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/16 22:20:59 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "../Libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef enum e_type
{
	COMMAND,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	HAPPEND
}			t_type;

typedef struct s_token
{
	char			*content;
	t_type			type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef enum e_quote
{
	NO_QUOTE,
	S_QUOTE,
	D_QUOTE
}			t_quote;

/* ************************************************************************** */
/*                               Parsing prompt                               */
/* ************************************************************************** */

t_token	*new_token(char *content, t_type type);
void	add_token(t_token **token, t_token *next);

void	append_token(t_token **token, char **line);
void	heredoc_token(t_token **token, char **line);
void	word_token(t_token **token, char **line, char *word, t_quote quote);
void	init_token(t_token **token, char **line, char *word, t_quote quote);

int		is_token(char c);
t_token	*parse_token(char *line);
t_quote	quote_state(char *line, t_quote quote);
int		check_quote(char *line, t_quote quote);

void	free_token(t_token *token);
void	ft_exit(t_token *token, char *line);

#endif