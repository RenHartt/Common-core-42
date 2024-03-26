/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:22:51 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/25 12:58:48 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

extern int	g_exit_code;

void	check_directory(t_cmd *tmp)
{
	if (tmp->cmd && ft_is_directory(tmp->cmd[0]) == 1 && tmp->path && \
		ft_is_directory(tmp->path) == 1)
	{
		printf("%s: is a directory\n", tmp->cmd[0]);
		g_exit_code = 126;
		free(tmp->path);
		tmp->path = NULL;
	}
}

char	*check_path(char *cmd)
{
	if (!ft_strncmp(cmd, "/", 1))
		return (ft_strdup(cmd));
	if (!ft_strncmp(cmd, "./", 2))
	{
		if (ft_check_permissions(cmd + 2) == 1)
		{
			printf("Minishell: %s: Permission denied\n", cmd + 2);
			return (NULL);
		}
		return (ft_strdup(cmd + 2));
	}
	return (NULL);
}

char	*search_in_env(t_env *env, char *cmd, char *path)
{
	int	i;

	while (env)
	{
		if (!ft_strncmp(env->name, "PATH", ft_strlen(env->name)))
		{
			i = 0;
			g_exit_code = 0;
			while (env->value[i])
			{
				if (ft_is_directory(path) == 1)
					return (NULL);
				path = ft_strjoin("/", cmd, 0b00);
				path = ft_strjoin(env->value[i], path, 0b01);
				if (!access(path, X_OK))
					return (path);
				free(path);
				path = NULL;
				i++;
			}
		}
		env = env->next;
	}
	return (NULL);
}

char	*find_path(char *cmd, t_env *env)
{
	char	*path;

	path = NULL;
	if (is_builtin(cmd))
		return (NULL);
	if (!ft_strncmp(cmd, "/", 1) || !ft_strncmp(cmd, "./", 2))
		return (check_path(cmd));
	path = search_in_env(env, cmd, path);
	if (path)
		return (path);
	printf("%s: command not found\n", cmd);
	g_exit_code = 127;
	free(path);
	return (NULL);
}

t_cmd	*init_cmd(t_token *token, t_env **env)
{
	t_cmd	*cmd;
	t_cmd	*tmp;

	cmd = NULL;
	if (token)
		add_cmd(&cmd, new_cmd(env));
	tmp = cmd;
	if (!tmp)
		return (NULL);
	while (token)
	{
		parse_token(&tmp, &token);
		check_directory(tmp);
		if (!tmp->cmd || !tmp->cmd[0])
		{
			add_cmd_and_next(&tmp, &token, env);
			tmp = tmp->next;
			continue ;
		}
		tmp->path = find_path(tmp->cmd[0], *env);
		add_cmd_and_next(&tmp, &token, env);
		tmp = tmp->next;
	}
	return (cmd);
}
