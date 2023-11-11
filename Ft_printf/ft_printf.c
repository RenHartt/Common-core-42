/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:46:28 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/11 17:35:20 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *type, ...)
{
	va_list	args;
	size_t	i;

	va_start (args, type);
	i = 0;
	while (type[i])
	{
		if (type[i] == '%')
		{
			ft_sort(&args, (char *)type, i + 1);
			i++;
		}
		else
		{
			ft_putchar(type[i]);
			i++;
		}
	}
	va_end(args);
	return (0);
}

