/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:44:57 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/16 22:39:53 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	print_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		printf("{%s} -> ", tmp->content);
		if (tmp->type == COMMAND)
			printf("COMMAND\n");
		else if (tmp->type == PIPE)
			printf("PIPE\n");
		else if (tmp->type == REDIR_IN)
			printf("REDIR_IN\n");
		else if (tmp->type == REDIR_OUT)
			printf("REDIR_OUT\n");
		else if (tmp->type == HERE_DOC)
			printf("HERE_DOC\n");
		else if (tmp->type == HAPPEND)
			printf("HAPPEND\n");
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_token	*token;
	t_token	*tmp;

	(void)argc;
	(void)argv;
	(void)envp;
	while (1)
	{
		line = readline("\001\033[30;47;1m\002minishell\
\001\033[0m\002 \001\033[30;47;1m\002>\001\033[0m\002 ");
		if (!line)
			ft_exit(NULL, line);
		token = parse_token(line);
		tmp = token;
		print_token(tmp);
		free_token(token);
		free(line);
	}
	return (0);
}
