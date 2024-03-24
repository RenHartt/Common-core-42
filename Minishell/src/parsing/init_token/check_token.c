/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:02:27 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 17:57:23 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

extern int	g_exit_code;

t_token	*last_token(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

int	check_pipe(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	if (tmp && (tmp->type == PIPE || last_token(tmp)->type != COMMAND))
		return (1);
	while (tmp)
	{
		if (tmp->type == PIPE)
		{
			if (!tmp->next || tmp->next->type == PIPE)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_redir(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == REDIR_IN || tmp->type == REDIR_OUT \
			||tmp->type == APPEND || tmp->type == HERE_DOC)
		{
			if (!tmp->next || tmp->next->type != COMMAND)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_heredoc(t_token *token)
{
	t_token	*tmp;
	int		count;

	tmp = token;
	count = 0;
	while (tmp)
	{
		if (tmp->type == HERE_DOC)
			count++;
		tmp = tmp->next;
	}
	return (count > 16);
}

int	check_token(t_token *token)
{
	if ((token->content[0] == '.') && ft_strlen(token->content) == 1)
	{
		g_exit_code = 2;
		ft_putendl_fd("minishell: .: filename argument required", 2);
		return (1);
	}
	if ((token->content[0] == '/') && ft_strlen(token->content) == 1)
	{
		g_exit_code = 126;
		ft_putendl_fd("minishell: /: Is a directory", 2);
		return (1);
	}
	if (check_pipe(token))
		return (1);
	if (check_redir(token))
		return (1);
	if (check_heredoc(token))
		return (1);
	return (0);
}
