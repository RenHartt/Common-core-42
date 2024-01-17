/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:39:01 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/17 20:23:43 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_std(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

void	ft_close_fd(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->tmpfile);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		i;
	char	*cmd[] = {"/usr/bin/cat", NULL};

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	i = 0;
	pipex->tmpfile = dup(STDIN_FILENO);
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (i < 2)
	{
		pipe(pipex->fd);
		pipex->pid[i] = fork();
		if (pipex->pid[i] == 0)
		{
			if (i == 0)
				dup2(pipex->infile, STDIN_FILENO);
			else
				dup2(pipex->tmpfile, STDIN_FILENO);
			if (i == 1)
				dup2(pipex->outfile, STDOUT_FILENO);
			else
				dup2(pipex->fd[1], STDOUT_FILENO);
			ft_close_fd(pipex);
			execve(cmd[0], cmd, envp);
			ft_close_std();
		}
		else
		{
			close(pipex->fd[1]);
			close(pipex->tmpfile);
			pipex->tmpfile = pipex->fd[0];
		}
		i++;
	}
	ft_close_fd(pipex);
	i = 0;
	while (i < 2)
		waitpid(pipex->pid[i++], NULL, 0);
	free(pipex);
}

	// execve ( "binary name", "args", "envp")
	// args -> char** {'/usr/bin/cat', '-e', NULL}

	//./pipex file1 cmd1 cmd2 file2
	//{/PATH/TO/BINARY/cmd1, NULL}
	// "cat -e"