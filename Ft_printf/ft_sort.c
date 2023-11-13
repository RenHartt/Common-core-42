/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:10:56 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/13 15:39:58 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort(va_list	*args, char *str, size_t i)
{
	if (str[i] == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (str[i] == 's')
		return ft_putstr(va_arg(*args, char *));
	else if (str[i] == 'p')
		return ft_pointer(va_arg(*args, unsigned long long), "0123456789abcdef");
	else if (str[i] == 'd' || str[i] == 'i')
		return ft_putnbr(va_arg(*args, int));
	else if (str[i] == 'u')
		return ft_putnbr_base(va_arg(*args, unsigned int), "0123456789");
	else if (str[i] == 'x')
		return ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (str[i] == 'X')
		return ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (str[i] == '%')
		return ft_putchar('%');
	return(0);
}