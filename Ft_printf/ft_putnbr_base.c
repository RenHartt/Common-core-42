/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:49:01 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/12 16:04:43 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long long nb, char *base)
{
	if (nb < ft_strlen(base))
		return (ft_putchar(base[nb]));
	return (ft_putnbr_base(nb / ft_strlen(base), base) + ft_putchar(base[nb % ft_strlen(base)]));
}