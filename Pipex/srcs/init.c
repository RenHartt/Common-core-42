/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:30:21 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/23 23:24:16 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*ft_init_pipex(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	if (!ft_strncmp(argv[1], "here_doc", 9))
		pipex->infile = open("here_doc", O_RDONLY);
	else
		pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		free(pipex);
		exit(EXIT_FAILURE);
	}
	pipex->tmpfile = dup(STDIN_FILENO);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (pipex);
}

t_cmd	*ft_init_cmd(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;
	int		i;

	i = 2;
	cmd = ft_new_cmd(argv[i], envp);
	while (argv[++i] && i < argc - 1)
		ft_add_cmd(&cmd, ft_new_cmd(argv[i], envp));
	return (cmd);
}
