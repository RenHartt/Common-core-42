/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:19:17 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/03 15:24:21 by bgoron           ###   ########.fr       */
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

int	ft_lst_is_sort(t_stack *a)
{
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_find_index(t_stack *a, int nbr)
{
	int i;

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
	int i;

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
