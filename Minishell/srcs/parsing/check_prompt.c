/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:32:44 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/17 17:08:02 by bgoron           ###   ########.fr       */
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

int	check_quote(char *line, t_quote quote)
{
	while (*line)
		quote = quote_state(line++, quote);
	return (quote);
}

