/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:44:57 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 16:13:47 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int __attribute__((unused))argc, \
char __attribute__((unused))**argv, char **envp)
{
	t_env	*env;
	t_token	*token;
	t_cmd	*cmd;
	char	*line;
	char	*prompt;

	init_shell(envp, &env);
	while (1)
	{
		prompt = get_prompt();
		line = readline(prompt);
		free(prompt);
		if (line && *line)
			add_history(line);
		if (!line)
			exit_minishell(env);
		token = parse_line(&line, env);
		cmd = init_cmd(token, &env);
		handle_heredoc(token, cmd);
		free_token(token);
		exec_line(cmd);
		free_cmd(cmd);
	}
	return (0);
}
