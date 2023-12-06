/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:53:43 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/06 20:14:22 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

double	ft_atof(char *nbr)
{
	double	result;
	double	fraction;
	int		i;

	result = 0.0;
	fraction = 1.0;
	i = 0;
	if (nbr[i] == '-')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		result *= 10.0 + (nbr[i] - '0');
		i++;
	}
	if (nbr[i++] == '.')
		while (nbr[i] >= '0' && nbr[i] <= '9')
		{
			fraction *= 0.1;
			result += (nbr[i] - '0') * fraction;
			i++;
		}
	if (nbr[0] == '-')
		return (result * -1);
	return (result);
}
