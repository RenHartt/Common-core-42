/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctabjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:31:06 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/26 17:26:12 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_ctablen(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

static int	ft_ctabslen(char **tab)
{
	int	len;

	len = 0;
	while (*tab)
		len += ft_strlen(*tab++) + 1;
	return (len);
}

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
		*(dst++) = *(src++);
	*dst = '\0';
}

char	*ft_ctabjoin(char **tab, char *sep)
{
	char	*new;
	char	*tmp;

	if (!tab)
		return (NULL);
	new = malloc(ft_ctabslen(tab) + ft_ctablen(tab) * ft_strlen(sep) + 1);
	if (!new)
		return (NULL);
	tmp = new;
	while (*tab)
	{
		ft_strcpy(tmp, *tab);
		tmp += ft_strlen(*tab);
		if (*(tab + 1))
		{
			ft_strcpy(tmp, sep);
			tmp += ft_strlen(sep);
		}
		tab++;
	}
	*tmp = '\0';
	free(sep);
	return (new);
}
