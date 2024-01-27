/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:04:46 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/27 18:06:42 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_usage(void)
{
	ft_putstr_fd("Usage: ./pipex infile cmd ... cmd outfile\n", 2);
	ft_putstr_fd("or\n", 2);
	ft_putstr_fd("Usage: ./pipex here_doc LIMITER cmd ... cmd outfile\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_usage_here_doc(void)
{
	ft_putstr_fd("Usage: ./pipex here_doc limiter cmd ... cmd outfile\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_exec(t_pipex *pipex, t_cmd *cmd, int i)
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
			ft_exec(pipex, cmd, i);
		close(pipex->fd[1]);
		close(pipex->tmpfile);
		pipex->tmpfile = pipex->fd[0];
		cmd = cmd->next;
		i++;
	}
	while (i > 0)
		waitpid(pipex->pid[--i], NULL, 0);
}

int	ft_here_doc(char *d)
{
	char	*l;
	int		fd1;
	int		fd2;

	l = NULL;
	fd1 = open(".tmpfile", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd1 == -1)
		ft_error();
	fd2 = dup(fd1);
	while (ft_strncmp(l, d, ft_strlen(d)) || ft_strlen(l) != ft_strlen(d) + 1)
	{
		ft_putstr_fd(l, fd1);
		free(l);
		ft_putstr_fd("heredoc> ", 1);
		l = get_next_line(STDIN_FILENO, 1);
	}
	free(l);
	get_next_line(0, 0);
	close(fd2);
	fd2 = open(".tmpfile", O_RDONLY);
	if (fd2 == -1)
		ft_error();
	close(fd1);
	unlink(".tmpfile");
	return (fd2);
}
