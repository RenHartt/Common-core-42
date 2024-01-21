/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:51:48 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/21 17:41:20 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*ft_init_pipex(t_pipex	*pipex, int argc, char **argv)
{
	pipex->tmpfile = dup(STDIN_FILENO);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		free(pipex);
		ft_error();
	}
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (pipex);
}

void	ft_child(t_pipex *pipex, t_cmd *cmd)
{
	dup2(pipex->fd[1], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	ft_close_fd(pipex);
	execve(cmd->path, cmd->cmd, NULL);
}

void	ft_parent(t_pipex *pipex, t_cmd *cmd)
{
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	ft_close_fd(pipex);
	execve(cmd->path, cmd->cmd, NULL);
}

void	ft_pipex(t_pipex *pipex, t_cmd *cmd)
{
	int		i;

	i = 0;
	while (cmd)
	{
		if (!i % 2)
			pipe(pipex->fd);
		pipex->pid[i] = fork();
		if (!pipex->pid[i++])
		{
			if (!i)
				ft_child(pipex, cmd);
			else if (cmd->next)
				ft_child(pipex, cmd);
			else
				ft_parent(pipex, cmd);
		}
		if (!i)
			close(pipex->fd[1]);
		else if (cmd->next)
			close(pipex->fd[1]);
		else
			close(pipex->fd[0]);
		cmd = cmd->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	t_cmd	*cmd;
	int		i;

	if (argc < 5)
		ft_error();
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (0);
	pipex = ft_init_pipex(pipex, argc, argv);
	i = 2;
	cmd = ft_new_cmd(argv[i], envp);
	while (argv[++i] && i < argc - 1)
		ft_add_cmd(&cmd, ft_new_cmd(argv[i], envp));
	ft_pipex(pipex, cmd);
	i = 0;
	while (i < argc - 3)
		waitpid(pipex->pid[i++], NULL, 0);
	ft_close_fd(pipex);
	ft_close_std();
	ft_free_cmd(cmd);
	free(pipex);
	return (0);
}
