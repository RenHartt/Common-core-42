/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:51:48 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/26 22:55:56 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	t_cmd	*cmd;

	if (argc >= 5)
	{
		if (!ft_strcmp(argv[1], "here_doc"))
		{
			if (argc < 6)
				ft_usage_here_doc();
			pipex = ft_init_pipex(argc, argv, 3);
			cmd = ft_init_cmd(argc, argv, envp, 3);
		}
		else
		{
			pipex = ft_init_pipex(argc, argv, 2);
			cmd = ft_init_cmd(argc, argv, envp, 2);
		}
		ft_pipex(pipex, cmd);
		ft_exit(pipex, cmd);
	}
	ft_usage();
	return (0);
}
