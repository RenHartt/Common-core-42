/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:49:54 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/25 14:42:44 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

extern int	g_exit_code;

t_cmd	*new_cmd(t_env **env)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd = NULL;
	new->path = NULL;
	new->redir = NULL;
	new->env = env;
	new->infile = 0;
	new->outfile = 1;
	new->heredoc_file = 0;
	new->fd[0] = 0;
	new->fd[1] = 1;
	new->empty = 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_cmd(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*tmp;

	tmp = *cmd;
	if (!tmp)
		*cmd = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void	parse_token(t_cmd **tmp, t_token **token)
{
	(*tmp)->empty = 0;
	while (*token && (*token)->type != PIPE)
	{
		if ((*token)->type == REDIR_IN || (*token)->type == REDIR_OUT || \
			(*token)->type == APPEND || (*token)->type == HERE_DOC)
		{
			add_redir(&(*tmp)->redir, \
			new_redir((*token)->type, (*token)->next->content));
			*token = (*token)->next;
		}
		else if ((*token)->type == COMMAND)
			ft_extand_tab(&(*tmp)->cmd, (*token)->content);
		*token = (*token)->next;
	}
}

void	add_cmd_and_next(t_cmd **tmp, t_token **token, t_env **env)
{
	if (*token)
	{
		*token = (*token)->next;
		add_cmd(&(*tmp), new_cmd(env));
	}
}
