/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:14:45 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/14 18:46:27 by bgoron           ###   ########.fr       */
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

int	is_token(char c)
{
	return ((c == '|') || (c == '<') || (c == '>'));
}

int	is_white_space(char c)
{
	return ((c == ' ') || ((c >= 9) && (c <= 13)));
}

t_token	*parse_token(char *line)
{
	t_token	*token;
	char	*word;

	token = (t_token *)malloc(sizeof(t_token));
	while (*line)
	{
		while (is_white_space(*line))
			line++;
		if (!ft_strncmp(line, "<<", 2))
		{
			token = add_token(token, "<<", HERE_DOC);
			line++;
		}
		else if (!ft_strncmp(line, ">>", 2))
		{
			token = add_token(token, ">>", HAPPEND);
			line++;
		}
		else if (*line == '|')
			token = add_token(token, "|", PIPE);
		else if (*line == '<')
			token = add_token(token, "<", REDIR_OUT);
		else if (*line == '>')
			token = add_token(token, ">", REDIR_IN);
		else
		{
			while (!is_token(*line) && !is_white_space(*line))
				
		}
		line++;
	}
	return (token);
}
