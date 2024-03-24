/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:43:27 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 17:37:44 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	last_is_heredoc(t_redir *redir)
{
	t_redir	*tmp;
	t_type	last;

	tmp = redir;
	last = -1;
	while (tmp)
	{
		if (tmp->type == HERE_DOC || tmp->type == REDIR_IN)
			last = tmp->type;
		tmp = tmp->next;
	}
	return (last == HERE_DOC);
}

char	*ft_random(int size, char *file)
{
	int	i;
	int	fd;

	i = 0;
	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (NULL);
	file[0] = '.';
	read(fd, file + 1, size);
	while (++i < size)
		file[i] = (file[i] % 26) + 97;
	file[i] = '\0';
	close(fd);
	return (file);
}

void	write_heredoc(char *line, char *limiter, int fd, t_cmd *cmd)
{
	fd = open(cmd->heredoc_name, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0600);
	while (1)
	{
		free(line);
		line = readline("heredoc> ");
		if (!line || (!ft_strncmp(line, limiter, ft_strlen(limiter)) \
		&& !line[ft_strlen(limiter)]))
			break ;
		replace_vars(&line, *cmd->env, NO_QUOTE);
		ft_putendl_fd(line, fd);
	}
	free(line);
	close(fd);
}

int	heredoc(char *limiter, t_token *token, t_cmd *cmd, t_cmd *tmp)
{
	char	*line;
	pid_t	pid;
	int		fd;

	fd = 0;
	line = NULL;
	ft_random(10, tmp->heredoc_name);
	pid = fork();
	if (!pid)
	{
		write_heredoc(line, limiter, fd, tmp);
		rl_clear_history();
		free_token(token);
		free_env(*cmd->env);
		free_cmd(cmd);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, NULL, 0);
	fd = open(tmp->heredoc_name, O_RDONLY);
	unlink(tmp->heredoc_name);
	return (fd);
}

void	handle_heredoc(t_token *token, t_cmd *cmd)
{
	t_cmd	*tmp;
	t_redir	*redir_tmp;
	int		fd;

	tmp = cmd;
	while (tmp)
	{
		fd = 0;
		redir_tmp = tmp->redir;
		while (redir_tmp)
		{
			if (redir_tmp->type == HERE_DOC)
			{
				if (fd)
					close(fd);
				fd = heredoc(redir_tmp->file, token, cmd, tmp);
				tmp->heredoc_file = fd;
			}
			redir_tmp = redir_tmp->next;
		}
		tmp = tmp->next;
	}
}
