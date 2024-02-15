/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:14:45 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/15 12:27:32 by bgoron           ###   ########.fr       */
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

t_token	*add_token(t_token *token, char *content, t_type type)
{
	t_token	*new;
	t_token	*tmp;

	new = new_token(content, type);
	if (!new)
		return (NULL);
	tmp = token;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (token);
}

int	is_white_space(char c)
{
	return ((c == ' ') || ((c >= 9) && (c <= 13)));
}

size_t	ft_strcsnp(char *s, char *reject)
{
	size_t	i;

	i = 0;
	while (s[i] && !ft_strchr(reject, s[i]))
		i++;
	return (i);
}

void	heredoc_token(t_token *token, char **line)
{
	token = add_token(token, "<<", HERE_DOC);
	(*line)++;
}

void	append_token(t_token *token, char **line)
{
	token = add_token(token, ">>", HAPPEND);
	(*line)++;
}

void	word_token(t_token *token, char **line, char *word)
{
	word = ft_strndup(*line, ft_strcsnp(*line, "\t\n\v\f\r'\" <>|"));
	token = add_token(token, word, WORD);
	*line += ft_strlen(word);
	(*line)--;
}

void	simple_quote_token(t_token *token, char **line, char *word)
{
	(*line)++;
	word = ft_strndup(*line, ft_strcsnp(*line, "\'"));
	token = add_token(token, word, WORD);
	*line += ft_strlen(word);
	(*line)++;
}

void	double_quote_token(t_token *token, char **line, char *word)
{
	(*line)++;
	word = ft_strndup(*line, ft_strcsnp(*line, "\""));
	token = add_token(token, word, WORD);
	*line += ft_strlen(word);
	(*line)++;
}

void	init_token(t_token *token, char **line, char *word)
{
	while (is_white_space(**line))
		(*line)++;
	if (!ft_strncmp(*line, "<<", 2))
		heredoc_token(token, line);
	else if (!ft_strncmp(*line, ">>", 2))
		append_token(token, line);
	else if (**line == '|')
		token = add_token(token, "|", PIPE);
	else if (**line == '<')
		token = add_token(token, "<", REDIR_OUT);
	else if (**line == '>')
		token = add_token(token, ">", REDIR_IN);
	else if (**line == '\'')
		simple_quote_token(token, line, word);
	else if (**line == '\"')
		double_quote_token(token, line, word);
	else
		word_token(token, line, word);
	(*line)++;
}

t_token	*parse_token(char *line)
{
	t_token	*token;
	char	*word;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	word = NULL;
	while (*line)
		init_token(token, &line, word);
	free(word);
	return (token);
}
