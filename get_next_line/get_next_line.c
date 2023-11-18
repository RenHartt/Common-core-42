/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:25:43 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/18 14:59:09 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*newstatic(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	str = ft_substr(str, i + 1, ft_strlen(str) - i);
	return (str);
}

char	*fill(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\n')
		i++;
	str2 = ft_calloc(i + 2, sizeof(char));
	if (!str1)
		return (NULL);
	i = 0;
	while (str1[i] != '\n')
	{
		str2[i] = str1[i];
		i++;
	}
	if (str1[i] == '\n')
		str2[i] = '\n';
	str2[i + 1] = '\0';
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
		if (r == -1)
		{
			free(curent);
			return (NULL);
		}
		curent[r] = '\0';
		line = ft_strjoin(line, curent);
	}
	free(curent);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char 		*tmp;

	tmp = NULL;
	if (!line)
		line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	line = rfile(fd, line);
	tmp = fill(line, tmp);
	line = newstatic(line);
	return (tmp);
}