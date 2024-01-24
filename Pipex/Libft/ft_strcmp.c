/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:31:04 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/25 00:29:02 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return (-1);
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((int)((unsigned char)*str1 - (unsigned char)*str2));
}
