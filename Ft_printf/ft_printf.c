/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:46:28 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/13 19:18:26 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *type, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	va_start (args, type);
	i = 0;
	count = 0;
	while (type[i])
	{
		if (type[i] == '%' && ft_isinset(type[i + 1], "cspdiuxX%"))
		{
			count += ft_orient(&args, (char *)type, i + 1);
			i += 2;
		}
		else
		{
			count += ft_putchar(type[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
