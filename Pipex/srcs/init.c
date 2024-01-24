/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:30:21 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/24 17:17:59 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*ft_init_pipex(int argc, char **argv, int i)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	if (i == 2)
		pipex->infile = open(argv[1], O_RDONLY);
	else
		pipex->infile = open("tmp", O_RDONLY);
	pipex->tmpfile = dup(STDIN_FILENO);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (pipex);
}

t_cmd	*ft_init_cmd(int argc, char **argv, char **envp, int i)
{
	t_cmd	*cmd;

	cmd = ft_new_cmd(argv[i], envp);
	while (argv[++i] && i < argc - 1)
		ft_add_cmd(&cmd, ft_new_cmd(argv[i], envp));
	return (cmd);
}
