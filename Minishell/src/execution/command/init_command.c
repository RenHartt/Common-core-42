/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:22:51 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 17:26:15 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

extern int	g_exit_code;

char	*find_path(char *cmd, t_env *env)
{
	char	*path;
	int		i;

	path = NULL;
	if (!ft_strncmp(cmd, "/", 1))
		return (ft_strdup(cmd));
	if (!ft_strncmp(cmd, "./", 2))
	{
		if (ft_check_permissions(cmd + 2) == 1)
		{
			printf("Minishell: %s: Permission denied\n", cmd + 2);
			return NULL;
		}
		return (ft_strdup(cmd + 2));
	}
	while (env)
	{
		if (!ft_strncmp(env->name, "PATH", ft_strlen(env->name)))
		{
			i = 0;
			g_exit_code = 0;
			while (env->value[i])
			{
				if (ft_is_directory(path) == 1)
				{
					free(path);
					path = NULL;
					return (NULL);
				}
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
	printf("%s: command not found\n", cmd);
	g_exit_code = 127;
	free(path);
	return (NULL);
}


// char	*find_path(char *cmd, t_env *env)
// {
// 	char	*path;
// 	int		i;

// 	path = NULL;
// 	if (!ft_strncmp(cmd, "/", 1) && !access(cmd, X_OK))
// 		return (ft_strdup(cmd));
// 	while (env)
// 	{
// 		if (!ft_strncmp(env->name, "PATH", ft_strlen(env->name)))
// 		{
// 			i = 0;
// 			while (env->value[i])
// 			{
// 				path = ft_strjoin("/", cmd, 0b00);
// 				path = ft_strjoin(env->value[i], path, 0b01);
// 				if (!access(path, X_OK))
// 					return (path);
// 				free(path);
// 				i++;
// 			}
// 		}
// 		env = env->next;
// 	}
// 	return (NULL);
// }

void	parse_token(t_cmd **tmp, t_token **token)
{
	(*tmp)->empty = 0;
	while (*token && (*token)->type != PIPE)
	{
		if ((*token)->type == REDIR_IN || (*token)->type == REDIR_OUT || \
			(*token)->type == APPEND || (*token)->type == HERE_DOC)
		{
			add_redir(&(*tmp)->redir, \
			new_redir((*token)->type, (*token)->next->content));
			*token = (*token)->next;
		}
		else if ((*token)->type == COMMAND)
			ft_extand_tab(&(*tmp)->cmd, (*token)->content);
		*token = (*token)->next;
	}
}

void	add_cmd_and_next(t_cmd **tmp, t_token **token, t_env **env)
{
	if (*token)
	{
		*token = (*token)->next;
		add_cmd(&(*tmp), new_cmd(env));
	}
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
		if (tmp->cmd && ft_is_directory(tmp->cmd[0]) == 1 && tmp->path && \
			ft_is_directory(tmp->path) == 1)
		{
			printf("%s: is a directory\n", tmp->cmd[0]);
			g_exit_code = 126;
			free(tmp->path);
			tmp->path = NULL;
		}
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
