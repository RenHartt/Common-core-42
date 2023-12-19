/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:19:17 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/19 17:33:45 by bgoron           ###   ########.fr       */
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

int	ft_cost_a(t_stack *a, int nbr, int *move)
{
	static t_stack	*tmp;
	int				cost;
	int				min;
	int				max;

	tmp = a;
	*move = 1;
	min = ft_lstfind_min(a);
	max = ft_lstfind_max(a);
	if (nbr > max || nbr < min)
		return (ft_find_index(a, min));
	while (!(a->nbr > nbr && ft_lstlast(a) < nbr))
		a = a->next;
	if (ft_find_index(tmp, nbr) > ft_lstsize(tmp) / 2)
		cost = ft_lstsize(tmp) - ft_find_index(tmp, nbr);
	else
	{
		cost = ft_find_index(tmp, nbr);
		*move = -1;
	}
	return (cost);
}

int	ft_cost_b(t_stack *b, int *move)
{
	int cost;

	*move = 1;
	if (ft_find_index(b, b->nbr) > ft_lstsize(b) / 2)
		cost = ft_lstsize(b) - ft_find_index(b, b->nbr);
	else
	{
		cost = ft_find_index(b, b->nbr);
		*move = -1;
	}
	return (cost);
}