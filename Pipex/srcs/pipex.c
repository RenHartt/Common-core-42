/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:51:48 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/20 18:32:14 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char**envp)
{
	t_pipex		pipex;
	t_cmd		*cmd;
	int			i;

	i = 0;
	if (argc != 5)
	{
		ft_putendl_fd("usage: ./pipex infile cmd1 cmd2 outfile", 2);
		return (0);
	}
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cmd = ft_new_cmd(argv[2], envp);
	ft_add_cmd(&cmd, ft_new_cmd(argv[3], envp));
	while (cmd)
	{
		cmd->cmd = ft_get_cmd(argv[i + 2]);
		cmd->path = ft_get_path(cmd->cmd[0], envp);
		ft_print_cmd(cmd);
		cmd = cmd->next;
		i++;
	}
	return (0);
}