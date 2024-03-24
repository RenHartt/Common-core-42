/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:33:25 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 17:43:04 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

// int	is_builtin(char *cmd)
// {
// 	return (!ft_strncmp(cmd, "echo", 5)
// 		|| !ft_strncmp(cmd, "cd", 3)
// 		|| !ft_strncmp(cmd, "pwd", 4)
// 		|| !ft_strncmp(cmd, "export", 7)
// 		|| !ft_strncmp(cmd, "unset", 6)
// 		|| !ft_strncmp(cmd, "env", 4)
// 		|| !ft_strncmp(cmd, "exit", 5));
// }

int	is_builtin(char *cmd)
{
	if(!ft_strncmp(cmd, "echo", 5))
		return (1);
	else if (!ft_strncmp(cmd, "cd", 3))
		return (1);
	else if (!ft_strncmp(cmd, "pwd", 4))
		return (1);
	else if (!ft_strncmp(cmd, "export", 7))
		return (1);
	else if (!ft_strncmp(cmd, "unset", 6))
		return (1);
	else if (!ft_strncmp(cmd, "env", 4))
		return (1);
	else if (!ft_strncmp(cmd, "exit", 5))
		return (1);
	return (0);
}

void	exec_builtin(t_cmd *cmd)
{
	if (cmd && cmd->cmd && !ft_strncmp(cmd->cmd[0], "echo", 5))
		ft_echo(cmd);
	else if (cmd && cmd->cmd && !ft_strncmp(cmd->cmd[0], "cd", 3))
		ft_cd(cmd->cmd[1], cmd->env);
	else if (cmd && cmd->cmd && !ft_strncmp(cmd->cmd[0], "pwd", 4))
		ft_pwd(cmd);
	else if (cmd && cmd->cmd && !ft_strncmp(cmd->cmd[0], "export", 7))
		ft_export(cmd);
	else if (cmd && cmd->cmd && !ft_strncmp(cmd->cmd[0], "unset", 6))
		ft_unset(cmd);
	else if (cmd && cmd->cmd && !ft_strncmp(cmd->cmd[0], "env", 4))
		ft_env(cmd);
	else if (cmd && cmd->cmd && !ft_strncmp(cmd->cmd[0], "exit", 5))
		ft_exit(cmd);
}
