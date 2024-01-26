/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:04:46 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/27 00:00:04 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first(t_pipex *pipex, t_cmd *cmd)
{
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	ft_close_fd(pipex);
	execve(cmd->path, cmd->cmd, NULL);
}

void	ft_middle(t_pipex *pipex, t_cmd *cmd)
{
	dup2(pipex->tmpfile, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	ft_close_fd(pipex);
	execve(cmd->path, cmd->cmd, NULL);
}

void	ft_last(t_pipex *pipex, t_cmd *cmd)
{
	dup2(pipex->tmpfile, STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	ft_close_fd(pipex);
	execve(cmd->path, cmd->cmd, NULL);
}

void	ft_pipex(t_pipex *pipex, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		pipe(pipex->fd);
		pipex->pid[i] = fork();
		if (!pipex->pid[i])
		{
			if (i == 0)
				ft_first(pipex, cmd);
			else if (cmd->next)
				ft_middle(pipex, cmd);
			else
				ft_last(pipex, cmd);
		}
		close(pipex->fd[1]);
		close(pipex->tmpfile);
		pipex->tmpfile = pipex->fd[0];
		cmd = cmd->next;
		i++;
	}
	while (i > 0)
		waitpid(pipex->pid[--i], NULL, 0);
}

int	here_doc(char *limiter)
{
	char	*line;
	int		fd1;
	int		fd2;

	line = NULL;
	fd1 = open(".tmpfile", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	fd2 = dup(fd1);
	while (ft_strncmp(line, limiter, ft_strlen(limiter)))
	{
		ft_putstr_fd(line, fd1);
		free(line);
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(fd2);
	fd2 = open(".tmpfile", O_RDONLY);
	close(fd1);
	unlink(".tmpfile");
	return (fd2);
}
