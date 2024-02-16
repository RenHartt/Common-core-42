/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:44:57 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/16 14:28:23 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	ft_exit(t_token *token, char *line)
{
	free_token(token);
	free(line);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	char	*line;
	t_token	*token;
	t_token	*tmp;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			ft_exit(NULL, line);
		token = parse_token(line);
		tmp = token;
		while (tmp)
		{
			printf("({%s}[%d])\n", tmp->content, tmp->type);
			tmp = tmp->next;
		}
		free_token(token);
		free(line);
	}
}