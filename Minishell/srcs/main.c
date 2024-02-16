/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:44:57 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/16 13:40:04 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	main(void)
{
	char	*line;
	t_token	*token;
	t_token	*tmp;

	line = ft_strdup("<<cat ''fdhgdf'' >>''|g '' p\"'\" fdh\"fshfgj\" -l>test");
	token = parse_token(line);
	tmp = token;
	while (tmp)
	{
		printf("({%s}[%d])", tmp->content, tmp->type);
		if (tmp->next)
			printf(" -> ");
		else
			printf("\n");
		tmp = tmp->next;
	}
	free_token(token);
	free(line);
	return (0);
}
