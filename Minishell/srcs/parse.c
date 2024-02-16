/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:14:45 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/16 14:20:48 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_token	*new_token(char *content, t_type type)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_token(t_token **token, t_token *next)
{
	t_token	*tmp;

	if (!token || !next)
		return ;
	if (!*token)
	{
		*token = next;
		return ;
	}
	tmp = *token;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = next;
	next->prev = tmp;
}

void	free_token(t_token *token)
{
	t_token	*next;

	next = NULL;
	if (!token)
		return ;
	while (token)
	{
		next = token->next;
		free(token->content);
		free(token);
		token = next;
	}
}

void	heredoc_token(t_token **token, char **line)
{
	add_token(token, new_token(ft_strdup("<<"), HERE_DOC));
	(*line)++;
}

void	append_token(t_token **token, char **line)
{
	add_token(token, new_token(ft_strdup(">>"), HAPPEND));
	(*line)++;
}

void	word_token(t_token **token, char **line, char *word)
{
	word = ft_strndup(*line, ft_strcsnp(*line, "\t\n\v\f\r <>|"));
	add_token(token, new_token(word, WORD));
	*line += ft_strlen(word) - 1;
}

void	simple_quote_token(t_token **token, char **line, char *word)
{
	(*line)++;
	word = ft_strndup(*line, ft_strcsnp(*line, "'"));
	word = ft_strjoin(ft_strdup("'"), word, 3);
	word = ft_strjoin(word, ft_strdup("'"), 3);
	add_token(token, new_token(word, WORD));
	*line += ft_strlen(word);
}

void	double_quote_token(t_token **token, char **line, char *word)
{
	(*line)++;
	word = ft_strndup(*line, ft_strcsnp(*line, "\""));
	word = ft_strjoin(ft_strdup("\""), word, 3);
	word = ft_strjoin(word, ft_strdup("\""), 3);
	add_token(token, new_token(word, WORD));
	*line += ft_strlen(word);
}

void	init_token(t_token **token, char **line, char *word)
{
	while (**line && ft_is_white_space(**line))
		(*line)++;
	if (**line && !ft_strncmp(*line, "<<", 2))
		heredoc_token(token, line);
	else if (**line && !ft_strncmp(*line, ">>", 2))
		append_token(token, line);
	else if (**line == '|')
		add_token(token, new_token(ft_strdup("|"), PIPE));
	else if (**line == '<')
		add_token(token, new_token(ft_strdup("<"), REDIR_OUT));
	else if (**line == '>')
		add_token(token, new_token(ft_strdup(">"), REDIR_IN));
	/*else if (**line == '\'')
		simple_quote_token(token, line, word);
	else if (**line == '"')
		double_quote_token(token, line, word);*/
	else
		word_token(token, line, word);
	(*line)++;
}

t_token	*parse_token(char *line)
{
	t_token	*token;
	char	*word;

	token = NULL;
	word = NULL;
	while (*line)
		init_token(&token, &line, word);
	free(word);
	return (token);
}
