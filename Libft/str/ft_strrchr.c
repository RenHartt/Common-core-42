/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:05:04 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/26 17:27:22 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0 && s[i] != (unsigned char)c)
		i--;
	if (i == 0 && (unsigned char)c != 0 && (unsigned char)c != s[i])
		return (NULL);
	return ((char *)(s + i));
}
