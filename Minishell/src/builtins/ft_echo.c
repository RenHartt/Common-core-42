/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:23:01 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/24 19:02:32 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_echo(t_cmd *cmd)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (cmd->cmd[i] && !ft_strncmp(cmd->cmd[i], "-n", 2))
	{
		n = 1;
		i++;
	}
	while (cmd->cmd[i])
	{
		ft_putstr_fd(cmd->cmd[i], 1);
		if (cmd->cmd[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!n)
		ft_putchar_fd('\n', 1);
}
