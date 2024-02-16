/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:14:45 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/16 22:11:58 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	check_quote(char *line, t_quote quote)
{
	while (*line)
		quote = quote_state(line++, quote);
	return (quote);
}

void	init_token(t_token **token, char **line, char *word, t_quote quote)
{
	while (**line && ft_is_white_space(**line))
		(*line)++;
	if (quote == NO_QUOTE)
	{
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
	}
	word_token(token, line, word, quote);
	(*line)++;
}

t_token	*parse_token(char *line)
{
	t_token	*token;
	char	*word;

	token = NULL;
	word = NULL;
	if (check_quote(line, NO_QUOTE))
		return (NULL);
	while (*line)
		init_token(&token, &line, word, NO_QUOTE);
	free(word);
	return (token);
}
