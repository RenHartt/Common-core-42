/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:25:43 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/20 17:54:23 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*restfile(char *str)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!str)
		return (ft_calloc(1, 1));
	while (str[i] && str[i] != '\n')
		i++;
	tmp = ft_substr(str, i + 1, ft_strlen(str) - i);
	free(str);
	return (tmp);
}

char	*readedline(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] && str1[i] != '\n')
		i++;
	str2 = ft_calloc(i + 2, sizeof(char));
	if (!str1)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		str2[i] = str1[i];
		if (str1[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*readfile(int fd, char *line)
{
	int		r;
	char	*buffer;

	r = 1;
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r <= 0)
		{
			free(buffer);
			return (line);
		}
		buffer[r] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*tmp;

	tmp = NULL;
	line[fd] = readfile(fd, line[fd]);
	if (line[fd] == NULL)
		return (NULL);
	tmp = readedline(line[fd], tmp);
	line[fd] = restfile(line[fd]);
	if (!ft_strchr(tmp, '\n'))
	{
		free(line[fd]);
		if (!*tmp)
		{
			free(tmp);
			tmp = NULL;
		}
		line[fd] = NULL;
	}
	return (tmp);
}
