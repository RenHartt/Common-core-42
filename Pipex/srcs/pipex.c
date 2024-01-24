/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:51:48 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/24 17:56:41 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		ft_usage();
	if (pipe(fd) == -1)
		ft_error();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line) > 0)
		{
			if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
				exit(EXIT_SUCCESS);
			ft_putstr_fd("here_doc > ", 1);
			ft_putstr_fd(line, fd[1]);
		}
	}
	ft_putstr_fd("here_doc > ", 1);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	t_cmd	*cmd;
	int		i;

	i = 2;
	if (argc >= 5)
	{
		if (!ft_strncmp(argv[1], "here_doc", 8))
		{
			here_doc(argv[2], argc);
			i = 3;
		}
		pipex = ft_init_pipex(argc, argv, i);
		cmd = ft_init_cmd(argc, argv, envp, i);
		ft_pipex(pipex, cmd);
		ft_close_fd(pipex);
		ft_free_cmd(cmd);
		free(pipex);
		return (0);
	}
	ft_usage();
}
