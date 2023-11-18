/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:25:55 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/18 21:03:42 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	free(s1);
	s3[i + j] = '\0';
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if ((unsigned char)c != '\0' && s[i] == '\0')
		return (NULL);
	return ((char *)(s + i));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size / size != nmemb)
		return (NULL);
	tab = malloc (nmemb * size);
	if (tab == NULL)
		return (NULL);
	while (i < size * nmemb)
	{
		*(unsigned char *)(tab + i) = '\0';
		i++;
	}
	return (tab);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s + start);
	tab = ft_calloc(len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (len > 0)
	{
		tab[i] = s[i + start];
		i++;
		len--;
	}
	tab[i] = '\0';
	return (tab);
}
