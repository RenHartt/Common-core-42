/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:10:56 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/13 19:19:57 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_orient(va_list *args, char *str, size_t i)
{
	char	*decbase;
	char	*hexabase;
	char	*hexabasemaj;

	decbase = "0123456789";
	hexabase = "0123456789abcdef";
	hexabasemaj = "0123456789ABCDEF";
	if (str[i] == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (str[i] == 'p')
		return (ft_pointer(va_arg(*args, unsigned long long), hexabase));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (str[i] == 'u')
		return (ft_putnbr_base(va_arg(*args, unsigned int), decbase));
	else if (str[i] == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), hexabase));
	else if (str[i] == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), hexabasemaj));
	else if (str[i] == '%')
		return (ft_putchar('%'));
	return (0);
}
