/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:03:56 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/31 16:03:08 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_usage(void)
{
	ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_open_failed(t_pipex *pipex)
{
	if (pipex)
		free(pipex);
	perror("Error");
}

void	ft_command_failed(t_cmd *cmd)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(cmd->cmd[0], 2);
	ft_putstr_fd("\n", 2);
}

void	ft_skip(t_pipex *pipex, t_cmd *cmd)
{
	ft_close_std();
	ft_free_cmd(cmd);
	free(pipex);
	exit(EXIT_FAILURE);
}

void	ft_exit(t_pipex *pipex, t_cmd *cmd)
{
	ft_close_fd(pipex);
	ft_free_cmd(cmd);
	free(pipex);
	exit(EXIT_SUCCESS);
}
