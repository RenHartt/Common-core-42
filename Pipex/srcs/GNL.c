/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:25:40 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/27 00:01:17 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_gnljoin(char *s1, char *s2)
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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			r;

	line = ft_calloc(1, 1);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (buffer && line)
	{
		line = ft_gnljoin(line, buffer);
		if (ft_isendline(line, buffer))
			return (line);
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 1)
		{
			free(buffer);
			if (line[0] != '\0')
				return (line);
			free(line);
			return (NULL);
		}
		buffer[r] = '\0';
	}
	return (NULL);
}
