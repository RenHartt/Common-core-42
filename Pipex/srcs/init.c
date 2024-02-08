/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:30:21 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/31 16:15:56 by bgoron           ###   ########.fr       */
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
	tmp = ft_strjoin("/", cmd);
	path_tab = ft_split(envp[i] + 5, ':');
	i = 0;
	path = ft_strjoin(path_tab[i], tmp);
	while (path_tab[i] && access(path, F_OK) == -1)
	{
		free(path);
		path = ft_strjoin(path_tab[i], tmp);
		i++;
	}
	ft_free_char_tab(path_tab);
	free(tmp);
	return (path);
}

t_cmd	*ft_new_cmd(char *cmd, char **envp)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd = ft_split(cmd, ' ');
	if (new->cmd[0] && !access(new->cmd[0], F_OK))
		new->path = ft_strdup(new->cmd[0]);
	else if (!new->cmd[0])
		new->path = ft_strdup("");
	else
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

t_pipex	*ft_init_pipex(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->status = 0;
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], \
	O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1 || pipex->infile == -1)
		pipex->status = -1;
	pipex->tmpfile = dup(STDIN_FILENO);
	return (pipex);
}

t_cmd	*ft_init_cmd(int argc, char **argv, char **envp)
{
	int		i;
	t_cmd	*cmd;

	i = 2;
	cmd = ft_new_cmd(argv[i], envp);
	while (argv[++i] && i < argc - 1)
		ft_add_cmd(&cmd, ft_new_cmd(argv[i], envp));
	return (cmd);
}
