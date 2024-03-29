/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:19:17 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/09 14:58:57 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstlast(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
		a = a->next;
	return (a->nbr);
}

int	ft_lstfind_min(t_stack *a)
{
	int	min;

	min = a->nbr;
	while (a)
	{
		if (a->nbr < min)
			min = a->nbr;
		a = a->next;
	}
	return (min);
}

int	ft_lstfind_max(t_stack *a)
{
	int	max;

	max = a->nbr;
	while (a)
	{
		if (a->nbr > max)
			max = a->nbr;
		a = a->next;
	}
	return (max);
}

int	ft_lstsize(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lst_cpy(t_stack *a)
{
	t_stack	*cpy;

	cpy = NULL;
	while (a)
	{
		ft_lstadd_back(&cpy, a->nbr);
		a = a->next;
	}
	return (cpy);
}
