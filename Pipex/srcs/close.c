/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:12:34 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/31 15:15:10 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->outfile);
	close(pipex->tmpfile);
	if (pipex->infile > 2)
		close(pipex->infile);
}

void	ft_close_std(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

void	ft_free_cmd(t_cmd *cmd)
{
	t_cmd	*current;
	t_cmd	*tmp;

	current = cmd;
	while (current)
	{
		tmp = current->next;
		ft_free_char_tab(current->cmd);
		free(current->path);
		free(current);
		current = tmp;
	}
}
