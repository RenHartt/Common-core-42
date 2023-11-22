/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:25:55 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/22 17:20:39 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
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
	if (!s1 || !s2)
		return (NULL);
	s3 = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (s3 == NULL)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (s3);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
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

int	ft_isendline(char *str, char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
	{
		i++;
		while (str[i])
		{
			buffer[j] = str[i];
			i++;
			j++;
		}
		buffer[j] = '\0';
		str[i - j] = '\0';
		return (1);
	}
	return (0);
}