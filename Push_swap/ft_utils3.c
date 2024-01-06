/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/06 17:05:13 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	return (nb * neg);
}

double	ft_atol(char *str)
{
	int	i;
	double	nb;
	double	neg;

	i = 0;
	nb = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	return (nb * neg);
}

void	ft_set_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 9 && str[i] <= 13)
			str[i] = ' ';
		i++;
	}
}

int	*ft_one_arg(char **argv)
{
	int		i;
	int		j;
	int		*tab;
	char	**str;

	i = 0;
	j = -1;
	ft_set_space(argv[1]);
	str = ft_split(argv[1], ' ');
	if (!str || !ft_is_int(str) || !ft_is_double(str))
	{
		ft_free_tab(str);
		ft_putstr("Error\n");
		return (NULL);
	}
	while (str[i])
		i++;
	tab = ft_calloc(sizeof(int), i);
	if (!tab)
		return (NULL);
	while (++j < i)
		tab[j] = ft_atoi(str[j]);
	ft_free_tab(str);
	return (tab);
}

int	*ft_many_arg(int argc, char **argv)
{
	int	i;
	int	*tab;

	i = 1;
	while (argv[i])
	{
		if (!ft_is_number(argv[i]) || !ft_is_int(&argv[i]) || !ft_is_double(&argv[i]))
		{
			ft_putstr("Error\n");
			return (NULL);
		}
		i++;
	}
	tab = ft_calloc(sizeof(int), (argc - 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		tab[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (tab);
}
