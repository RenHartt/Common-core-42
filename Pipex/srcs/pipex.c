/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:51:48 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/23 19:03:05 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	t_cmd	*cmd;

	if (argc >= 5)
	{
		pipex = ft_init_pipex(argc, argv);
		cmd = ft_init_cmd(argc, argv, envp);
		ft_pipex(pipex, cmd);
		ft_close_fd(pipex);
		ft_free_cmd(cmd);
		free(pipex);
		return (0);
	}
	ft_usage();
}
