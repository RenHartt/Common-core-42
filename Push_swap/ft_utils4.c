/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:33:32 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/06 15:14:46 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_double(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]) && i != j)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (!((str[i - 1] >= 9 && str[i - 1] <= 13) || (str[i - 1] == ' ')) && i != 0)
				return (0);
			else if (!ft_is_digit(str[i + 1]))
				return (0);
			i++;
		}
		else if (ft_is_digit(str[i]))
			i++;
		else if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_is_int(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_number(str[i]) || ft_atol(str[i]) > 2147483647)
			return (0);
		else if (!ft_is_number(str[i]) || ft_atol(str[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}