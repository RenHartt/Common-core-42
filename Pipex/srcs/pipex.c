/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:51:48 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/30 00:18:17 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	t_cmd	*cmd;
	int		i;

	i = 2;
	if (argc >= 5)
	{
		if (!ft_strcmp(argv[1], "here_doc"))
		{
			if (argc < 6)
				ft_usage();
			i = 3;
		}
		pipex = ft_init_pipex(argc, argv, i);
		if (pipex->status == -1)
			perror("Error");
		cmd = ft_init_cmd(argc, argv, envp, i);
		ft_pipex(envp, pipex, cmd);
		ft_exit(pipex, cmd);
	}
	ft_usage();
	return (0);
}
