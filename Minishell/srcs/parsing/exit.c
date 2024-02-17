/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:07:04 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/17 16:35:18 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	free_token(t_token *token)
{
	t_token	*next;

	next = NULL;
	if (!token)
		return ;
	while (token)
	{
		next = token->next;
		free(token->content);
		free(token);
		token = next;
	}
}

void	ft_exit(t_token *token, char *line)
{
	free_token(token);
	free(line);
	exit(EXIT_SUCCESS);
}
