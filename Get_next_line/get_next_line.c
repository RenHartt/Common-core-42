/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:25:43 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/22 17:47:03 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		line = ft_strjoin(line, buffer);
		if (ft_isendline(line, buffer))
			return (line);
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 1)
		{
			free(buffer);
			buffer = NULL;
			if (line[0] != '\0')
				return (line);
			free(line);
			return (NULL);
		}
		buffer[r] = '\0';
	}
	return (NULL);
}
