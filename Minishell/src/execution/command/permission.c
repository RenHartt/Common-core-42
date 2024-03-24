/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:29:22 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 17:24:53 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

extern int	g_exit_code;

int	ft_check_permissions(char *path)
{
	if (access(path, X_OK) && errno == EACCES)
	{
		g_exit_code = 126;
		return (1);
	}
	return (0);
}

int	ft_is_directory(char *path)
{
	int	fd;

	if (!path)
		return (0);
	fd = open(path, O_RDWR);
	if (fd == -1 && errno == EISDIR)
	{
		printf("Minishell: %s: Is a directory\n", path);
		g_exit_code = 126;
		if (fd > 0)
			close(fd);
		return (1);
	}
	if (fd > 0)
		close(fd);
	return (0);
}
