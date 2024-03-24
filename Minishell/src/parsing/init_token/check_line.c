/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 01:33:15 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/12 23:44:41 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	is_token(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_var_name(char *line, int len)
{
	if (ft_isdigit(*(line + 1)))
		return (0);
	if ((ft_isalnum(*(line + len)) || *(line + len) == '_'))
		return (1);
	return (0);
}

int	check_quote(char *line, t_quote quote)
{
	while (*line)
		quote = quote_state(line++, quote);
	return (quote);
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
