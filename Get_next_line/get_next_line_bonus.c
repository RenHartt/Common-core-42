/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:25:43 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/22 17:52:16 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			r;

	line = ft_calloc(1, 1);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (buffer[fd] && line)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_isendline(line, buffer[fd]))
			return (line);
		r = read(fd, buffer[fd], BUFFER_SIZE);
		if (r < 1)
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
			if (line[0] != '\0')
				return (line);
			free(line);
			return (NULL);
		}
		buffer[fd][r] = '\0';
	}
	return (NULL);
}
