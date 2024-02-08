/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:50:04 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/08 18:34:19 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnljoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	s3 = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (s3 == NULL)
		return (NULL);
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i + j] = s2[j];
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

char	*get_next_line(int fd, int i)
{
	static char	*buffer;
	char		*line;
	int			r;

	if (!i)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(2, sizeof(char));
	if (!line)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(2, sizeof(char));
	while (buffer && line)
	{
		line = ft_gnljoin(line, buffer);
		if (ft_isendline(line, buffer))
			return (line);
		r = read(fd, buffer, 1);
		if (r < 1)
			return (line);
	}
	return (NULL);
}
