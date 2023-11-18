/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:25:43 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/18 20:59:07 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*newstatic(char *str)
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

char	*fill(char *str1, char *str2)
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

char	*rfile(int fd, char *line)
{
	int		r;
	char	*curent;

	r = 1;
	curent = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!curent)
		return (NULL);
	while (!ft_strchr(curent, '\n') && r != 0)
	{
		r = read(fd, curent, BUFFER_SIZE);
		if (r <= 0)
		{
			free(curent);
			return (line);
		}
		curent[r] = '\0';
		line = ft_strjoin(line, curent);
	}
	free(curent);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*tmp;

	tmp = NULL;
	line[fd] = rfile(fd, line[fd]);
	if (line[fd] == NULL)
		return (NULL);
	tmp = fill(line[fd], tmp);
	line[fd] = newstatic(line[fd]);
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
