/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:39:01 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/18 12:06:04 by bgoron           ###   ########.fr       */
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

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*ft_get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i] + 5);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	**ft_get_cmd(char **argv, char **envp)
{
	int		i;
	char	*path;
	char	**cmd;
	char	**path_tab;

	i = 0;
	path = ft_get_path(envp);
	path_tab = ft_split(path, ':');
	while (path_tab[i])
	{
		path_tab[i] = ft_strjoin(path_tab[i], "/");
		path_tab[i] = ft_strjoin(path_tab[i], argv[2]);
		if (!access(path_tab[i], F_OK))
		{
			cmd = ft_split(path_tab[i], ' ');
			ft_free_tab(path_tab);
			free(path);
			return (cmd);
		}
		i++;
	}
	ft_free_tab(path_tab);
	free(path);
	return (NULL);
}

void	ft_pipe(t_pipex *pipex, char **envp, char **cmd, int i)
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
	close(pipex->fd[1]);
	close(pipex->tmpfile);
	pipex->tmpfile = pipex->fd[0];
}

t_pipex	*ft_init_pipex(t_pipex	*pipex, int argc, char **argv)
{
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	pipex->tmpfile = dup(STDIN_FILENO);
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	char	**cmd;
	int		i;

	pipex = NULL;
	pipex = ft_init_pipex(pipex, argc, argv);
	cmd = ft_get_cmd(argv, envp);
	i = 0;
	while (i++ < 2)
		ft_pipe(pipex, envp, cmd, i - 1);
	i = 0;
	while (i < 2)
		waitpid(pipex->pid[i++], NULL, 0);
	ft_close_fd(pipex);
	ft_free_tab(cmd);
	free(pipex);
	return (NULL);
}
