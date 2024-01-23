/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:48:27 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/23 23:09:40 by bgoron           ###   ########.fr       */
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
	if (!s3)
		return (NULL);
	while (s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[j++] = s2[i++];
	s3[j] = '\0';
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
			buffer[j++] = str[i++];
		buffer[j] = '\0';
		str[i - j - 1] = '\0';
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			r;

	line = ft_calloc(1, 1);
	buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (buffer[fd] && line)
	{
		line = ft_gnljoin(line, buffer[fd]);
		if (ft_isendline(line, buffer[fd]))
		{
			free(buffer[fd]);
			return (line);
		}
		r = read(fd, buffer[fd], BUFFER_SIZE);
		if (r < 1)
		{
			free(buffer[fd]);
			free(line);
			return (NULL);
		}
		buffer[fd][r] = '\0';
	}
	return (NULL);
}
