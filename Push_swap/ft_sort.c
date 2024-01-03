/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:45:30 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/03 15:39:45 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_a_to_b(t_stack **a, t_stack **b)
{
	int	min;
	int	max;
	int	median;

	while (*a)
	{
		min = ft_lstsize(*a) / 2;
		max = ft_lstsize(*a);
		median = ((max - min) / 2) + min;
		while (ft_lstsize(*a) > min)
		{
			if ((*a)->nbr > min)
			{
				ft_pb(a, b);
				if ((*b)->nbr < median)
					ft_rb(b);
			}
			else
				ft_ra(a);
		}
	}
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
			ft_pa(a, b);
		}
	}
}
