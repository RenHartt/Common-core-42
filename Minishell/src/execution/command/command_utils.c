/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:49:54 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 15:20:41 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_cmd	*new_cmd(t_env **env)
{
	t_cmd	*new;
	int		i;

	i = 0;
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
