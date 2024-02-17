/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:07:04 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/16 22:07:47 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

int	is_token(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

t_quote	quote_state(char *line, t_quote quote)
{
	if (*line == '\'' && quote == NO_QUOTE)
		quote = S_QUOTE;
	else if (*line == '"' && quote == NO_QUOTE)
		quote = D_QUOTE;
	else if (*line == '\'' && quote == S_QUOTE)
		quote = NO_QUOTE;
	else if (*line == '"' && quote == D_QUOTE)
		quote = NO_QUOTE;
	return (quote);
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

void	ft_exit(t_token *token, char *line)
{
	free_token(token);
	free(line);
	exit(EXIT_SUCCESS);
}
