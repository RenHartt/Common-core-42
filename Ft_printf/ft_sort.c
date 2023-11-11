/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:10:56 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/11 17:36:23 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort(va_list	*args, char *str, size_t i)
{
	if (str[i] == 'c')
		ft_putchar(va_arg(*args, int));
	else if (str[i] == 's')
		ft_putstr(va_arg(*args, char *));
	else if (str[i] == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_base(va_arg(*args, long long), "0123456789abcdef");
	}
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr_base(va_arg(*args, int), "0123456789");
	else if (str[i] == 'u')
		ft_putnbr_base(va_arg(*args, unsigned int), "0123456789");
	else if (str[i] == 'x')
		ft_putnbr_base(va_arg(*args, int), "0123456789abcdef");
	else if (str[i] == 'X')
		ft_putnbr_base(va_arg(*args, int), "0123456789ABCDEF");
	else if (str[i] == '%')
		ft_putchar('%');
	else
		ft_putchar('%');
}