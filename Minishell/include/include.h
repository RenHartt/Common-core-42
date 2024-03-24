/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:27:33 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 16:30:59 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <termios.h>
# include <signal.h>
# include <errno.h>

# define PROMPT "$ "

typedef enum e_quote
{
	NO_QUOTE,
	S_QUOTE,
	D_QUOTE
}			t_quote;

typedef enum e_type
{
	COMMAND,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	APPEND
}			t_type;

typedef struct s_token
{
	char			*content;
	t_type			type;
	struct s_token	*next;
	struct s_token	*prev;
}			t_token;

typedef struct s_env
{
	char			*name;
	char			**value;
	struct s_env	*next;
	struct s_env	*prev;
}			t_env;

typedef struct s_redir
{
	t_type			type;
	char			*file;
	struct s_redir	*next;
	struct s_redir	*prev;
}			t_redir;

typedef struct s_cmd
{
	char			**cmd;
	char			*path;
	int				fd[2];
	int				infile;
	int				outfile;
	char			heredoc_name[11];
	int				heredoc_file;
	int				empty;
	t_redir			*redir;
	t_env			**env;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}				t_cmd;

/* ************************************************************************** */
/*                                Parsing line                                */
/* ************************************************************************** */

t_token	*new_token(char *content, t_type type);
void	add_token(t_token **token, t_token *next);
t_token	*last_token(t_token *token);
void	append_token(t_token **token, char **line);
void	heredoc_token(t_token **token, char **line);
void	word_token(t_token **token, char **line, char *word, t_quote quote);
void	init_token(t_token **token, char *line, char *word, t_quote quote);
int		is_token(char c);
int		is_var_name(char *line, int len);
int		is_backslash_semicolon(char *line);
int		check_line(char *line);
int		check_quote(char *line, t_quote quote);
t_quote	quote_state(char *line, t_quote quote);
t_token	*parse_line(char **line, t_env *env);
int		check_token(t_token *token);
int		check_heredoc(t_token *token);

/* ************************************************************************** */
/*                                 Init env                                   */
/* ************************************************************************** */

t_env	*new_env(char *name, char **value);
void	add_env(t_env **env, t_env *next);
char	*get_var(char *name, t_env *env);
void	insert_var(char ***new, char *tmp, int *len, t_env *env);
void	quoted_skip(char **str, int len, t_quote *quote);
void	replace_vars(char **str, t_env *env, t_quote quote);
t_env	*parse_env(char **envp);
void	free_env(t_env *env);

/* ************************************************************************** */
/*                               Init Execution                               */
/* ************************************************************************** */

t_cmd	*new_cmd(t_env **env);
void	add_cmd(t_cmd **cmd, t_cmd *new);
t_redir	*new_redir(t_type type, char *file);
void	add_redir(t_redir **redir, t_redir *new);
char	*find_path(char *cmd, t_env *env);
t_cmd	*init_cmd(t_token *token, t_env **env);
int		ft_check_permissions(char *path);
int		ft_is_directory(char *path);
void	free_cmd(t_cmd *cmd);

/* ************************************************************************** */
/*                                 Execution                                  */
/* ************************************************************************** */

t_cmd	*first_cmd(t_cmd *cmd);
t_cmd	*last_cmd(t_cmd *cmd);
int		last_is_heredoc(t_redir *redir);
void	close_fd(t_cmd *tmp);
void	handle_heredoc(t_token *token, t_cmd *cmd);
void	manage_redir(t_cmd *cmd);
char	**env_string(t_env *env);
int		is_builtin(char *cmd);
void	exec_builtin(t_cmd *cmd);
void	exec_cmd(t_cmd *cmd);
void	exec_line(t_cmd *cmd);

/* ************************************************************************** */
/*                                  Builtins                                  */
/* ************************************************************************** */

void	ft_pwd(t_cmd *cmd);
void	ft_cd(char *path, t_env **env);
void	ft_echo(t_cmd *cmd);
void	ft_export(t_cmd *cmd);
void	ft_unset(t_cmd *cmd);
void	ft_env(t_cmd *cmd);
void	ft_exit(t_cmd *cmd);

/* ************************************************************************** */
/*                                   Signal                                   */
/* ************************************************************************** */

void	ignore_handler(int signum);
void	signal_handler(int signum);
char	*get_prompt(void);
void	init_shell(char **envp, t_env **env);

/* ************************************************************************** */
/*                                    Error                                   */
/* ************************************************************************** */

void	exit_minishell(t_env *env);
void	prompt_error(char *error, int code);
void	free_token_content(t_token *token);
void	free_token(t_token *token);
void	free_redir(t_redir *redir);
void	free_env(t_env *env);
void	free_cmd(t_cmd *cmd);

#endif