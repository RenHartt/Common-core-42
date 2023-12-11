/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:53:43 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/11 13:44:19 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb * size / size != nmemb)
		return (NULL);
	tab = malloc (nmemb * size);
	if (tab == NULL)
		return (NULL);
	while (i < size * nmemb)
	{
		*(unsigned char *)(tab + i) = '\0';
		i++;
	}
	return (tab);
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
		result = result * 10.0 + (nbr[i++] - '0');
	if (nbr[i++] == '.')
	{
		while (nbr[i] >= '0' && nbr[i] <= '9')
		{
			fraction *= 0.1;
			result += (nbr[i++] - '0') * fraction;
		}
	}
	if (nbr[0] == '-')
		return (result * -1);
	return (result);
}
