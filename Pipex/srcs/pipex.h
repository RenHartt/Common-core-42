/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:38:54 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/21 17:29:03 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int			fd[2];
	int			infile;
	int			outfile;
	int			tmpfile;
	pid_t		pid[1024];
}				t_pipex;

typedef struct s_cmd
{
	char			**cmd;
	char			*path;
	struct s_cmd	*next;
}				t_cmd;

void	ft_print_cmd(t_cmd *cmd);

t_pipex	*ft_init_pipex(t_pipex *pipex, int argc, char **argv);
t_cmd	*ft_new_cmd(char *cmd, char **envp);
void	ft_add_cmd(t_cmd **list, t_cmd *new);
char	*ft_get_path(char *cmd, char **envp);
void	ft_pipex(t_pipex *pipex, t_cmd *cmd);
void	ft_child(t_pipex *pipex, t_cmd *cmd);
void	ft_parent(t_pipex *pipex, t_cmd *cmd);
void	ft_free_cmd(t_cmd *cmd);
void	ft_close_fd(t_pipex *pipex);
void	ft_close_std(void);
void	ft_error(void);

#endif
