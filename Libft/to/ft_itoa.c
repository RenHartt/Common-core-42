/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 01:21:56 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/26 17:27:49 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	i;
	int		sign;

	i = ft_nbrlen(n);
	nbr = malloc((i * sizeof(char)) + 1);
	if (!nbr)
		return (NULL);
	nbr[0] = '0';
	if (n < 0)
	{
		sign = -1;
		nbr[0] = '-';
	}
	else
		sign = 1;
	nbr[i] = '\0';
	while (n)
	{
		nbr[i - 1] = (n % 10) * sign + '0';
		n /= 10;
		i--;
	}
	return (nbr);
}
