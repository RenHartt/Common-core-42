/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:29:25 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/13 19:15:31 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_pointer(unsigned long long nb, char *base)
{
	size_t	i;

	i = 0;
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (nb < ft_strlen(base))
	{
		write(1, "0x", 2);
		i += 2;
	}
	if (nb >= ft_strlen(base))
		i += ft_pointer(nb / ft_strlen(base), base);
	i += ft_putchar(base[nb % ft_strlen(base)]);
	return (i);
}
