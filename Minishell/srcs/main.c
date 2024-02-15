/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:44:57 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/15 12:29:11 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	main(void)
{
	char	*line;
	t_token	*token;
	
	line = ft_strdup("<<cat>>|gr'ep srcs|wc -l>test");
	token = parse_token(line);
	token = token->next;
	while (token)
	{
		printf("%s\n", token->content);
		printf("%d\n", token->type);
		token = token->next;
	}
	return (0);
}