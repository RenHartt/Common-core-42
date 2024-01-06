/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:04:03 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/06 20:34:47 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_find_index(t_stack *a, int nbr)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->nbr == nbr)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

int	ft_find_final_index(t_stack *a, int nbr)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->nbr < nbr)
			i++;
		a = a->next;
	}
	return (i);
}

void	ft_set_nbr_to_index(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a)
	{
		a->nbr = ft_find_final_index(tmp, a->nbr);
		a = a->next;
	}
}
