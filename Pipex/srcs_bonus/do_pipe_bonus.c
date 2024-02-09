/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:04:46 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/09 15:23:54 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	*ft_random(int size)
{
	int		i;
	int		fd;
	char	*random;

	i = 0;
	random = (char *)malloc(sizeof(char) * (size + 2));
	if (!random)
		return (NULL);
	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		ft_open_failed(NULL);
	random[0] = '.';
	read(fd, random + 1, size);
	while (++i < size)
		random[i] = (random[i] % 26) + 97;
	random[i] = '\0';
	close(fd);
	return (random);
}

char	*ft_write_in_here_doc(char *l, int fd1)
{
	if (!l || l[ft_strlen(l) - !!ft_strlen(l)] == '\n')
	{
		ft_putstr_fd(l, fd1);
		ft_putstr_fd("heredoc> ", 1);
	}
	free(l);
	l = get_next_line(STDIN_FILENO, 1);
	if (!l)
		l = ft_strdup("");
	return (l);
}

int	ft_here_doc(char *d)
{
	char	*l;
	char	*tmp;
	int		fd1;
	int		fd2;

	l = NULL;
	tmp = ft_random(10);
	fd1 = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd1 == -1)
		ft_open_failed(NULL);
	fd2 = dup(fd1);
	while (ft_strncmp(l, d, ft_strlen(d)) || ft_strlen(l) != ft_strlen(d) + 1)
	{
		if (!access(tmp, F_OK))
			l = ft_write_in_here_doc(l, fd1);
	}
	ft_end_here_doc(l, tmp, &fd1, &fd2);
	return (fd2);
}
