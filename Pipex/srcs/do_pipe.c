/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:04:46 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/09 14:44:45 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char **envp, t_pipex *pipex, t_cmd *cmd, int i)
{
	if (i == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
	}
	else if (cmd->next)
	{
		dup2(pipex->tmpfile, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(pipex->tmpfile, STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
	}
	ft_close_fd(pipex);
	if (!i && pipex->infile < 0)
		ft_skip(pipex, cmd);
	execve(cmd->path, cmd->cmd, envp);
	perror("Error");
	ft_close_std();
}

void	ft_pipex(char **envp, t_pipex *pipex, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		pipe(pipex->fd);
		pipex->pid[i] = fork();
		if (!pipex->pid[i])
			ft_exec(envp, pipex, cmd, i);
		close(pipex->fd[1]);
		close(pipex->tmpfile);
		pipex->tmpfile = pipex->fd[0];
		cmd = cmd->next;
		i++;
	}
	while (i > 0)
		waitpid(pipex->pid[--i], NULL, 0);
}
