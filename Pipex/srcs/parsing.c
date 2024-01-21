/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:04:54 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/21 17:16:03 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char *cmd, char **envp)
{
	char	*tmp;
	char	*path;
	char	**path_tab;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path_tab = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_tab[i])
	{
		tmp = ft_strjoin(path_tab[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(path, F_OK))
		{
			ft_free_char_tab(path_tab);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_char_tab(path_tab);
	return (NULL);
}

t_cmd	*ft_new_cmd(char *cmd, char **envp)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd = ft_split(cmd, ' ');
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

void	ft_print_cmd(t_cmd *cmd)
{
	int	i;

	while (cmd)
	{
		ft_putstr_fd("cmd: ", 1);
		ft_putendl_fd(cmd->cmd[0], 1);
		ft_putstr_fd("flags: ", 1);
		i = 1;
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
