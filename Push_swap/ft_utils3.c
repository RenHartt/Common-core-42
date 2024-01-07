/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/07 18:27:25 by bgoron           ###   ########.fr       */
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
	int		i;
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

int ft_strlentab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_stack	*ft_one_arg(char **argv)
{
	int		i;
	int		j;
	char	**str;
	t_stack	*tab;

	j = 0;
	tab = NULL;
	ft_set_space(argv[1]);
	str = ft_split(argv[1], ' ');
	if (!str || !ft_is_int(str) || !ft_is_double(str))
	{
		ft_free_tab(str);
		ft_putstr("Error\n");
		return (NULL);
	}
	i = ft_strlentab(str);
	tab = ft_lstnew(ft_atoi(str[0]));
	while (++j < i)
		ft_lstadd_back(tab, ft_atoi(str[j]));
	ft_free_tab(str);
	return (tab);
}

t_stack	*ft_many_arg(char **argv)
{
	int		i;
	int		j;
	t_stack	*tab;

	i = 1;
	j = 0;
	tab = NULL;
	while (argv[i])
	{
		if (!ft_is_number(argv[i]) || !ft_is_int(&argv[i]) \
		|| !ft_is_double(&argv[i]))
		{
			ft_putstr("Error\n");
			return (NULL);
		}
		i++;
	}
	tab = ft_lstnew(ft_atoi(argv[1]));
	while (++j < i - 1)
		ft_lstadd_back(tab, ft_atoi(argv[j + 1]));
	return (tab);
}
