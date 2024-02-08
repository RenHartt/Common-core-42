/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:51:48 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/31 15:19:48 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	t_cmd	*cmd;

	if (argc == 5)
	{
		pipex = ft_init_pipex(argc, argv);
		if (pipex->status == -1)
			perror("Error");
		cmd = ft_init_cmd(argc, argv, envp);
		ft_pipex(envp, pipex, cmd);
		ft_exit(pipex, cmd);
	}
	ft_usage();
	return (0);
}
