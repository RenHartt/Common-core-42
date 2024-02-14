/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:44:57 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/14 15:33:34 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

/*int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	*prompt;
	t_cmd	*cmd;

	(void)argc;
	(void)argv;
	(void)envp;
	line = NULL;
	prompt = ft_strdup("minishell > ");
	while (1)
	{
		line = readline(prompt);
	}
	return (0);
}*/

int	main(void)
{
	char	*line;
	t_token	*token;
	
	line = ft_strdup("ls -l | << grep >> srcs | wc-l > test");
	token = parse_token(line);
	while (token)
	{
		printf("%s\n", token->content);
		token = token->next;
	}
	return (0);
}