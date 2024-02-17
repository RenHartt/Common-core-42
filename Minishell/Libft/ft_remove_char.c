/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:37:20 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/15 19:40:54 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remove_char(char *str, char c)
{
	char	*new;
	char	*tmp;

	new = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	tmp = new;
	while (*str)
	{
		if (*str != c)
		{
			*tmp = *str;
			tmp++;
		}
		str++;
	}
	*tmp = '\0';
	return (new);
}
