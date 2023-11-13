/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:49:01 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/13 19:19:31 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nb, char *base)
{
	size_t	i;

	i = 0;
	if (nb >= ft_strlen(base))
		i += ft_putnbr_base(nb / ft_strlen(base), base);
	i += ft_putchar(base[nb % ft_strlen(base)]);
	return (i);
}
