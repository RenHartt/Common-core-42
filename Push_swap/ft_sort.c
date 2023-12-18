/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:45:30 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/18 15:22:57 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_three(t_stack **a)
{
	while (!ft_lst_is_sort(*a))
	{
		if (ft_lstfind_max(*a) == (*a)->nbr)
			ft_ra(a);
		if (ft_lstfind_max(*a) == (*a)->next->nbr)
			ft_rra(a);
		if (ft_lstfind_max(*a) == (*a)->next->next->nbr)
			ft_sa(a);
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int min;
	int max;
	int	median;
	while ((*a)->next)
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
