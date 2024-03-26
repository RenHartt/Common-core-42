/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:03:31 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 20:58:06 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

extern int	g_exit_code;

void	ignore_handler(int signum)
{
	(void)signum;
}

void	signal_handler(int signum)
{
	if (signum == 2)
	{
		printf("^C\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exit_code = 130;
	}
}

void	heredoc_signal_handler(int signum)
{
	if (signum == 2)
	{
		g_exit_code = 130;
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		printf("^C\n");
		close(0);
	}
}

char	*get_prompt(void)
{
	char	pwd[1024];
	char	*tmp;
	char	*prompt;

	tmp = getcwd(NULL, sizeof(char) * sizeof(pwd));
	ft_strlcpy(pwd, tmp, sizeof(pwd));
	free(tmp);
	prompt = ft_strjoin(pwd, PROMPT, 0);
	rl_set_prompt(prompt);
	return (prompt);
}

void	init_shell(char **envp, t_env **env)
{
	struct termios	new_termios;

	rl_catch_signals = 0;
	tcgetattr(0, &new_termios);
	if (tcsetattr(0, 0, &new_termios) != 0)
	{
		perror("tcsetattr");
		exit(1);
	}
	new_termios.c_lflag = new_termios.c_lflag & (~ECHOCTL);
	tcsetattr(0, 0, &new_termios);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	*env = parse_env(envp);
}
