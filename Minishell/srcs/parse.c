/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:14:45 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/14 16:23:08 by bgoron           ###   ########.fr       */
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

/*t_token	*parse_token(char *line)
{
	t_token	*token;
	char	**content;
	int		i;

	token = (t_token *)malloc(sizeof(t_token));
	i = 0;
	while (content[i])
	{
		if (content[i][0] == '|')
			token = add_token(token, content[i], PIPE);
		else if (!ft_strncmp(content[i], "<<", 2))
			token = add_token(token, content[i], HERE_DOC);
		else if (!ft_strncmp(content[i], ">>", 2))
			token = add_token(token, content[i], REDIR_HAPPEND);
		else if (content[i][0] == '<')
			token = add_token(token, content[i], REDIR_IN);
		else if (content[i][0] == '>')
			token = add_token(token, content[i], REDIR_OUT);
		else
			token = add_token(token, content[i], WORD);
		i++;
	}
	return (token);
}*/

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
	while (is_white_space(*line))
		line++;
	while (line)
	{
		if (*line == '|')
			token = add_token(token, "|", PIPE);
		else if (*line == '<')
			token = add_token(token, "<", REDIR_OUT);
		else if (*line == '>')
			token = add_token(token, ">", REDIR_IN);
		line++;
	}
	return (token);
}
