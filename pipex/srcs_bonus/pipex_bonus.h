/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:38:54 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/31 15:59:27 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int			fd[2];
	int			status;
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

t_pipex	*ft_init_pipex(int argc, char **argv, int i);
t_cmd	*ft_init_cmd(int argc, char **argv, char **envp, int i);

void	ft_pipex(char **envp, t_pipex *pipex, t_cmd *cmd);
int		ft_here_doc(char *limiter);

void	ft_end_here_doc(char *l, char *tmp, int *fd1, int *fd2);
void	ft_close_std(void);
void	ft_close_fd(t_pipex *pipex);
void	ft_free_cmd(t_cmd *cmd);
void	ft_exit(t_pipex *pipex, t_cmd *cmd);
void	ft_skip(t_pipex *pipex, t_cmd *cmd);
void	ft_open_failed(t_pipex *pipex);
void	ft_command_failed(t_cmd *cmd);

void	ft_usage(void);
void	ft_usage_here_doc(void);

#endif
