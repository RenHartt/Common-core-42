/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:12:34 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/27 16:59:44 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->tmpfile);
}

void	ft_close_std(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

void	ft_free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		ft_free_char_tab(tmp->cmd);
		free(tmp->path);
		free(tmp);
	}
}

void	ft_error(void)
{
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_exit(t_pipex *pipex, t_cmd *cmd)
{
	ft_close_fd(pipex);
	ft_free_cmd(cmd);
	free(pipex);
	exit(EXIT_SUCCESS);
}
