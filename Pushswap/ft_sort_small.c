/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:55:49 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/11 16:27:38 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_two(t_stack **a)
{
	if ((*a)->nbr > (*a)->next->nbr)
		ft_sa(a);
}

void	ft_sort_three(t_stack **a)
{
	int	i;
	int	j;
	int	k;

	i = (*a)->nbr;
	j = (*a)->next->nbr;
	k = (*a)->next->next->nbr;
	if (i < j && j > k && k > i)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (i > j && j > k && i > k)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (i > j && j < k && i < k)
		ft_sa(a);
	else if (i < j && j > k && i > k)
		ft_rra(a);
	else if (i > j && j < k && i > k)
		ft_ra(a);
	else
		return ;
}

void	ft_a_to_b(t_stack **a, t_stack **b)
{
	int	min;
	int	max;
	int	median;

	while (ft_lstsize(*a) > 3)
	{
		max = ft_lstsize(*a);
		min = max / 2;
		median = ((max - min) / 2) + min;
		while (ft_lstsize(*a) > 3 && ft_lstsize(*a) > min)
		{
			if ((*a)->nbr > min)
			{
				ft_pb(a, b);
				if (((*b)->nbr < median) && (ft_lstsize(*b) > 1))
					ft_rb(b);
			}
			else
				ft_ra(a);
		}
	}
	ft_sort_three(a);
}

void	ft_b_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if (ft_find_index(*b, ft_lstfind_max(*b)) > ft_lstsize(*b) / 2)
		{
			while ((*b)->nbr != ft_lstfind_max(*b))
				ft_rrb(b);
			ft_pa(a, b);
		}
		else
		{
			while ((*b)->nbr != ft_lstfind_max(*b))
				ft_rb(b);
			if (ft_lstlast(*a) > (*b)->nbr)
				ft_rra(a);
			else
				ft_pa(a, b);
		}
	}
	while (!ft_is_sorted(*a))
		ft_rra(a);
}

void	ft_sort_small(t_stack **a, t_stack **b)
{
	ft_a_to_b(a, b);
	ft_b_to_a(a, b);
}
