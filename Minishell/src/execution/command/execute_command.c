/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:07:09 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 17:48:48 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

extern int	g_exit_code;

void	manage_wrong_cmd(t_cmd *cmd)
{
	if ((!cmd->cmd \
	|| cmd->infile == -1 \
	|| cmd->outfile == -1 \
	|| (cmd->path && access(cmd->path, X_OK)) \
	|| (!cmd->path && access(cmd->cmd[0], X_OK))))
	{
		rl_clear_history();
		if (cmd->prev)
			close(cmd->prev->fd[0]);
		close(cmd->fd[0]);
		close(cmd->fd[1]);
		free_env(*cmd->env);
		free_cmd(first_cmd(cmd));
		g_exit_code = 127;
		exit(127);
	}
}

void	dup_close(t_cmd *cmd)
{
	if (cmd->infile != STDIN_FILENO && cmd->infile != -1)
	{
		dup2(cmd->infile, STDIN_FILENO);
		close(cmd->infile);
	}
	if (cmd->outfile != STDOUT_FILENO && cmd->outfile != -1)
	{
		dup2(cmd->outfile, STDOUT_FILENO);
		close(cmd->outfile);
	}
	if (cmd->next && cmd->outfile == STDOUT_FILENO)
		dup2(cmd->fd[1], STDOUT_FILENO);
	if (cmd->prev && cmd->infile == STDIN_FILENO)
		dup2(cmd->prev->fd[0], STDIN_FILENO);
	if (cmd->prev)
		close(cmd->prev->fd[0]);
	close(cmd->fd[0]);
	close(cmd->fd[1]);
}

void	exec(t_cmd *cmd)
{
	if (cmd && !cmd->empty)
	{
		dup_close(cmd);
		manage_wrong_cmd(cmd);
		if (is_builtin(cmd->cmd[0]))
			exec_builtin(cmd);
		else
		{
			if (cmd->path && cmd->cmd)
				execve(cmd->path, cmd->cmd, env_string(*cmd->env));
			else if (cmd->cmd)
				execve(cmd->cmd[0], cmd->cmd, env_string(*cmd->env));
			close(STDIN_FILENO);
			close(STDOUT_FILENO);
			close(STDERR_FILENO);
			exit(127);
		}
		rl_clear_history();
		free_env(*cmd->env);
		free_cmd(first_cmd(cmd));
		exit(EXIT_SUCCESS);
	}
}

void	exec_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	pid_t	pid[1024];
	int		i;

	tmp = cmd;
	if (!tmp)
		return ;
	i = 0;
	while (tmp)
	{
		pipe(tmp->fd);
		if (cmd && !cmd->empty)
			manage_redir(cmd);
		pid[i] = fork();
		if (!pid[i++])
			exec(tmp);
		close_fd(tmp);
		tmp = tmp->next;
	}
	while (i--)
		waitpid(pid[i], NULL, 0);
	close(last_cmd(cmd)->fd[0]);
}

void	exec_line(t_cmd *cmd)
{
	if (cmd && cmd->cmd && !cmd->next && is_builtin(cmd->cmd[0]))
		exec_builtin(cmd);
	else
		exec_cmd(cmd);
}
