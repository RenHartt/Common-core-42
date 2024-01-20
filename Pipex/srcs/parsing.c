/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:04:54 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/20 18:29:33 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_cmd(char *cmd)
{
	char	**cmd_tab;
	int		i;

	i = 0;
	cmd_tab = ft_split(cmd, ' ');
	return (cmd_tab);
}

char	*ft_get_path(char *cmd, char **envp)
{
	char	**path_tab;
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path_tab = ft_split(envp[i] + 5, ':');
		i++;
	}
	i = 0;
	while (path_tab[i] && access(path, F_OK))
	{
		path = ft_strjoin(path_tab[i], "/");
		path = ft_strjoin(path, cmd);
		i++;
	}
	return (path);
}

void	ft_print_cmd(t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd)
	{
		ft_putstr_fd("cmd: ", 1);
		ft_putendl_fd(cmd->cmd[0], 1);
		ft_putstr_fd("flags: ", 1);
		while (cmd->cmd[i])
		{
			ft_putstr_fd(cmd->cmd[i], 1);
			ft_putchar_fd(' ', 1);
			i++;
		}
		ft_putchar_fd('\n', 1);
		ft_putstr_fd("path: ", 1);
		ft_putendl_fd(cmd->path, 1);
		ft_putchar_fd('\n', 1);
		cmd = cmd->next;
	}
}

t_cmd	*ft_new_cmd(char *cmd, char **envp)
{
	t_cmd	*new;

	if (!(new = (t_cmd *)malloc(sizeof(t_cmd))))
		return (NULL);
	new->cmd = ft_get_cmd(cmd);
	new->path = ft_get_path(new->cmd[0], envp);
	new->next = NULL;
	return (new);
}

void	ft_add_cmd(t_cmd **list, t_cmd *new)
{
	t_cmd	*tmp;

	tmp = *list;
	if (!tmp)
		*list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
