/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:04:32 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/16 22:21:17 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

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

void	word_token(t_token **token, char **line, char *word, t_quote quote)
{
	int	i;

	i = 0;
	while (quote != NO_QUOTE || (!ft_is_white_space((*line)[i]) && \
	!is_token((*line)[i]) && (*line)[i]))
		quote = quote_state(*line + i++, quote);
	if (i)
	{
		word = ft_strndup(*line, i);
		add_token(token, new_token(word, COMMAND));
		*line += i - 1;
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
