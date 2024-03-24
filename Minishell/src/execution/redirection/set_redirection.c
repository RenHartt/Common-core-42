/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:32 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 13:42:22 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	redir_in(t_cmd *cmd, t_redir *tmp)
{
	if (cmd->infile != STDIN_FILENO)
		close(cmd->infile);
	cmd->infile = open(tmp->file, O_RDONLY);
}

void	redir_out(t_cmd *cmd, t_redir *tmp)
{
	if (cmd->outfile != STDOUT_FILENO)
		close(cmd->outfile);
	cmd->outfile = open(tmp->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

void	redir_append(t_cmd *cmd, t_redir *tmp)
{
	if (cmd->outfile != STDIN_FILENO)
		close(cmd->outfile);
	cmd->outfile = open(tmp->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
}

void	redir_heredoc(t_cmd *cmd)
{
	if (cmd->infile != STDIN_FILENO)
		close(cmd->infile);
	cmd->infile = cmd->heredoc_file;
}

void	manage_redir(t_cmd *cmd)
{
	t_redir	*tmp;

	tmp = cmd->redir;
	while (tmp)
	{
		if (tmp->type == REDIR_IN)
			redir_in(cmd, tmp);
		else if (tmp->type == REDIR_OUT)
			redir_out(cmd, tmp);
		else if (tmp->type == APPEND)
			redir_append(cmd, tmp);
		if (cmd->infile == -1 || cmd->outfile == -1)
			return ;
		tmp = tmp->next;
	}
	if (last_is_heredoc(cmd->redir))
		redir_heredoc(cmd);
}
