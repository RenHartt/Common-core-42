/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:23:06 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/25 14:19:40 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_env(t_env *env)
{
	int	i;

	if (!env)
		return ;
	while (env)
	{
		ft_putstr_fd(env->name, 1);
		ft_putchar_fd('=', 1);
		if (env->value)
		{
			i = 0;
			while (env->value[i])
			{
				if (i > 0)
					ft_putchar_fd(':', 1);
				ft_putstr_fd(env->value[i], 1);
				i++;
			}
		}
		else
			ft_putstr_fd("NULL", 2);
		ft_putchar_fd('\n', 1);
		env = env->next;
	}
}
