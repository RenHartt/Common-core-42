/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:49:01 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/11 17:34:24 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long long nb, char *base)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb < ft_strlen(base))
		ft_putchar(base[nb]);
	if (nb >= ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putchar(base[nb % ft_strlen(base)]);
	}
}