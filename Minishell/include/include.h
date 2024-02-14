/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:27:33 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/14 16:45:48 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "../Libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef enum e_type
{
	COMMAND,
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	HAPPEND
}				t_type;

typedef struct s_token
{
	char			*content;
	t_type			type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_cmd
{
	char			**cmd;
	char			*path;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_file
{
	pid_t		pid[1024];
	int			fd[2];
	int			infile;
	int			outfile;
	int			tmpfile;
}					t_file;

t_token	*parse_token(char *line);

#endif