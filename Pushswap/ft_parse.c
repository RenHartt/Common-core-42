/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:29:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/09 19:46:18 by bgoron           ###   ########.fr       */
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

t_stack	*ft_args(char **argv)
{
	int		i;
	int		j;
	char	**str;
	t_stack	*tab;

	i = 1;
	tab = NULL;
	while (argv[i])
	{
		j = 0;
		ft_set_space(argv[i]);
		str = ft_split(argv[i++], ' ');
		if (!str || !*str || !ft_is_int(str) || !ft_is_double(str))
		{
			ft_free_tab(str);
			ft_lstfree(tab);
			write(2, "Error\n", 6);
			return (NULL);
		}
		while (str[j])
			ft_lstadd_back(&tab, ft_atoi(str[j++]));
		ft_free_tab(str);
	}
	return (tab);
}

void	*ft_free_tab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}
